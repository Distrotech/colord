/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2011 Richard Hughes <richard@hughsie.com>
 *
 * Licensed under the GNU General Public License Version 2
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#if !defined (__COLORD_H_INSIDE__) && !defined (CD_COMPILATION)
#error "Only <colord.h> can be included directly."
#endif

#ifndef __CD_DEVICE_H
#define __CD_DEVICE_H

#include <glib-object.h>
#include <gio/gio.h>

#include <libcolord/cd-enum.h>
#include <libcolord/cd-profile.h>

G_BEGIN_DECLS

#define CD_TYPE_DEVICE		(cd_device_get_type ())
#define CD_DEVICE(o)		(G_TYPE_CHECK_INSTANCE_CAST ((o), CD_TYPE_DEVICE, CdDevice))
#define CD_DEVICE_CLASS(k)	(G_TYPE_CHECK_CLASS_CAST((k), CD_TYPE_DEVICE, CdDeviceClass))
#define CD_IS_DEVICE(o)		(G_TYPE_CHECK_INSTANCE_TYPE ((o), CD_TYPE_DEVICE))
#define CD_IS_DEVICE_CLASS(k)	(G_TYPE_CHECK_CLASS_TYPE ((k), CD_TYPE_DEVICE))
#define CD_DEVICE_GET_CLASS(o)	(G_TYPE_INSTANCE_GET_CLASS ((o), CD_TYPE_DEVICE, CdDeviceClass))
#define CD_DEVICE_ERROR		(cd_device_error_quark ())
#define CD_DEVICE_TYPE_ERROR	(cd_device_error_get_type ())

typedef struct _CdDevicePrivate CdDevicePrivate;

typedef struct
{
	 GObject		 parent;
	 CdDevicePrivate	*priv;
} CdDevice;

typedef struct
{
	GObjectClass		 parent_class;
	void			(*changed)		(CdDevice		*device);
	/*< private >*/
	/* Padding for future expansion */
	void (*_cd_device_reserved1) (void);
	void (*_cd_device_reserved2) (void);
	void (*_cd_device_reserved3) (void);
	void (*_cd_device_reserved4) (void);
	void (*_cd_device_reserved5) (void);
	void (*_cd_device_reserved6) (void);
	void (*_cd_device_reserved7) (void);
	void (*_cd_device_reserved8) (void);
} CdDeviceClass;

/**
 * CdDeviceError:
 * @CD_DEVICE_ERROR_FAILED: the transaction failed for an unknown reason
 *
 * Errors that can be thrown
 */
typedef enum
{
	CD_DEVICE_ERROR_FAILED,
	CD_DEVICE_ERROR_LAST
} CdDeviceError;

GType		 cd_device_get_type			(void);
GQuark		 cd_device_error_quark			(void);
CdDevice	*cd_device_new				(void);
gchar		*cd_device_to_string			(CdDevice	*device);
gboolean	 cd_device_set_object_path_sync		(CdDevice	*device,
							 const gchar	*object_path,
							 GCancellable	*cancellable,
							 GError		**error);
gboolean	 cd_device_set_model_sync		(CdDevice	*device,
							 const gchar	*value,
							 GCancellable	*cancellable,
							 GError		**error);
gboolean	 cd_device_set_serial_sync		(CdDevice	*device,
							 const gchar	*value,
							 GCancellable	*cancellable,
							 GError		**error);
gboolean	 cd_device_set_vendor_sync		(CdDevice	*device,
							 const gchar	*value,
							 GCancellable	*cancellable,
							 GError		**error);
gboolean	 cd_device_set_kind_sync		(CdDevice	*device,
							 CdDeviceKind	 kind,
							 GCancellable	*cancellable,
							 GError		**error);
gboolean	 cd_device_set_colorspace_sync		(CdDevice	*device,
							 CdColorspace	 colorspace,
							 GCancellable	*cancellable,
							 GError		**error);
gboolean	 cd_device_add_profile_sync		(CdDevice	*device,
							 CdProfile	*profile,
							 GCancellable	*cancellable,
							 GError		**error);
CdProfile	*cd_device_get_profile_for_qualifier_sync (CdDevice	*device,
							 const gchar	*qualifier,
							 GCancellable	*cancellable,
							 GError		**error);
gboolean	 cd_device_make_profile_default_sync	(CdDevice	*device,
							 CdProfile	*profile,
							 GCancellable	*cancellable,
							 GError		**error);
gboolean	 cd_device_profiling_inhibit_sync	(CdDevice	*device,
							 GCancellable	*cancellable,
							 GError		**error);
gboolean	 cd_device_profiling_uninhibit_sync	(CdDevice	*device,
							 GCancellable	*cancellable,
							 GError		**error);
const gchar	*cd_device_get_id			(CdDevice	*device);
const gchar	*cd_device_get_model			(CdDevice	*device);
const gchar	*cd_device_get_vendor			(CdDevice	*device);
const gchar	*cd_device_get_serial			(CdDevice	*device);
guint64		 cd_device_get_created			(CdDevice	*device);
guint64		 cd_device_get_modified			(CdDevice	*device);
CdDeviceKind	 cd_device_get_kind			(CdDevice	*device);
CdColorspace	 cd_device_get_colorspace		(CdDevice	*device);
GPtrArray	*cd_device_get_profiles			(CdDevice	*device);
CdProfile	*cd_device_get_default_profile		(CdDevice	*device);
const gchar	*cd_device_get_object_path		(CdDevice	*device);

G_END_DECLS

#endif /* __CD_DEVICE_H */

