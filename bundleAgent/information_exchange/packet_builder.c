/*
* Copyright (c) 2014 SeNDA
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* 
*     http://www.apache.org/licenses/LICENSE-2.0
* 
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
* 
*/

int build_nd_beacon(struct nd_beacon **new_beacon)
{
	char *announceables = NULL;
	int new_beacon_l = 0, announceables_l = 0;

	// Determine packet length
	new_beacon_l = sizeof(struct nd_beacon);
	if (world->announceable) {
		announceables_l = generate_announceables_string(&announceables);
		new_beacon_l += announceables_l;
	}
	new_beacon_l++; // \0 announceables string end

	// Create packet
	*new_beacon = (struct nd_beacon *)calloc(1, new_beacon_l);

	(*new_beacon)->id = ND_BEACON;
	snprintf((*new_beacon)->platform_id, sizeof((*new_beacon)->platform_id), "%s", world->platform_id);
	snprintf((*new_beacon)->platform_ip, sizeof((*new_beacon)->platform_ip), "%s", world->platform_ip);
	(*new_beacon)->platform_port = world->platform_port;

	if (world->announceable && announceables_l > 0) {
		strncpy((*new_beacon)->rit_announceables, announceables, new_beacon_l - sizeof(struct nd_beacon));
		free(announceables);
	} else {
		(*new_beacon)->rit_announceables[0] = '\0';
	}

	return new_beacon_l;
}

int build_nd_query(struct nd_query **new_nd_query)
{
	int new_nd_query_l = 0;

	new_nd_query_l = sizeof(struct nd_query);

	*new_nd_query = (struct nd_query *)calloc(1, new_nd_query_l);
	(*new_nd_query)->id = ND_QUERY;
	snprintf((*new_nd_query)->platform_id, sizeof((*new_nd_query)->platform_id), "%s", world->platform_id);

	return new_nd_query_l;
}