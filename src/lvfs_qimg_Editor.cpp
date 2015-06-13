/**
 * This file is part of lvfs-qimg.
 *
 * Copyright (C) 2011-2015 Dmitriy Vilkov, <dav.daemon@gmail.com>
 *
 * lvfs-qimg is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * lvfs-qimg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with lvfs-qimg. If not, see <http://www.gnu.org/licenses/>.
 */

#include "lvfs_qimg_Editor.h"
#include "gui/lvfs_qimg_ImageViewer.h"

#include <lvfs/IEntry>
#include <lvfs/IProperties>


namespace LVFS {
namespace QImg {

Editor::Editor(const Interface::Holder &file) :
    ExtendsBy(file)
{}

Editor::~Editor()
{}

void Editor::view(QWidget *parent)
{
    Interface::Holder fp = original()->as<IEntry>()->open();

    if (fp.isValid())
        if (IProperties *prop = original()->as<IProperties>())
        {
            size_t len = prop->size();
            uchar *buffer = new (std::nothrow) uchar[len];

            if (LIKELY(buffer != NULL))
            {
                if (fp->as<IStream>()->read(buffer, len) == len)
                {
                    QPixmap map;

                    if (map.loadFromData(buffer, len))
                    {
                        ImageViewer widget(parent);
                        widget.open(map);
                        widget.exec();
                    }
                }

                delete [] buffer;
            }
        }
}

}}
