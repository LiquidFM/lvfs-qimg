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

#include "lvfs_qimg_Package.h"
#include "lvfs_qimg_Plugin.h"


namespace LVFS {
namespace QImg {

Package::Package()
{}

Package::~Package()
{}

const char *Package::name() const
{
    return "QImg";
}

Settings::Scope *Package::settings() const
{
    return NULL;
}

const Package::Plugin **Package::contentPlugins() const
{
    static const QImg::Plugin plugin;
    static const Plugin types[] =
    {
        { "image/gif",                plugin },
        { "image/jpeg",               plugin },
        { "image/png",                plugin },
        { "image/bmp",                plugin },
        { "image/x-eps",              plugin },
        { "image/x-ico",              plugin },
        { "image/x-portable-bitmap",  plugin },
        { "image/x-portable-graymap", plugin },
        { "image/x-portable-pixmap",  plugin },
        { "image/x-xbitmap",          plugin },
        { "image/x-xpixmap",          plugin },
        { "image/tiff",               plugin },
        { "image/x-psd",              plugin },
        { "image/x-webp",             plugin }
    };
    enum { Count = sizeof(types) / sizeof(Plugin) };

    static const Plugin *res[Count + 1] = {};

    for (unsigned i = 0; i < Count; ++i)
        res[i] = &types[i];

    return res;
}

const Package::Plugin **Package::protocolPlugins() const
{
    return NULL;
}

}}


DECLARE_PLUGIN(::LVFS::QImg::Package)
