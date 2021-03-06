/*
 * drv_ssd_cold.c
 *
 * Copyright (C) 2014 Aerospike, Inc.
 *
 * Portions may be licensed to Aerospike, Inc. under one or more contributor
 * license agreements.
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Affero General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/
 */

#include "storage/drv_ssd.h"
#include <stdbool.h>
#include <stdint.h>
#include "fault.h"
#include "base/datamodel.h"
#include "storage/storage.h"


void
ssd_resume_devices(drv_ssds* ssds)
{
	// Should not get here - for enterprise version only.
	cf_crash(AS_DRV_SSD, "cold start called ssd_resume_devices()");
}


bool
ssd_cold_start_is_valid_n_bins(uint32_t n_bins)
{
	// FIXME - what should we do here?
	cf_assert(n_bins != 0, AS_DRV_SSD, CF_CRITICAL,
			"community edition found tombstone - erase drive and restart");

	return n_bins <= BIN_NAMES_QUOTA;
}


void
ssd_cold_start_adjust_cenotaph(as_namespace* ns, const drv_ssd_block* block,
		as_record* r)
{
	// Nothing to do - relevant for enterprise version only.
}


void
ssd_cold_start_transition_record(as_namespace* ns, const drv_ssd_block* block,
		as_record* r, bool is_create)
{
	// Nothing to do - relevant for enterprise version only.
}


void
ssd_cold_start_drop_cenotaphs(as_namespace* ns)
{
	// Nothing to do - relevant for enterprise version only.
}


void
as_storage_start_tomb_raider_ssd(as_namespace* ns)
{
	// Tomb raider is for enterprise version only.
}


int
as_storage_record_write_ssd(as_storage_rd* rd)
{
	// All record writes except defrag come through here!
	return as_bin_inuse_has(rd) ? ssd_write(rd) : 0;
}
