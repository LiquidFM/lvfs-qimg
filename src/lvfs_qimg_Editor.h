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

#ifndef LVFS_QIMG_EDITOR_H_
#define LVFS_QIMG_EDITOR_H_

#include <lvfs-core/IEditor>


namespace LVFS {
namespace QImg {

class PLATFORM_MAKE_PRIVATE Editor : public ExtendsBy<Core::IEditor>
{
public:
    Editor(const Interface::Holder &file);
    virtual ~Editor();

public: /* Core::IEditor */
    virtual void view(QWidget *parent);
};

}}

#endif /* LVFS_QIMG_EDITOR_H_ */
