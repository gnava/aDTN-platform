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

#ifndef INC_HASH_H
#define INC_HASH_H

/*Neighbours structures*/

struct nb_info {
	char id[MAX_PLATFORM_ID_LEN];
	char ip[STRING_IP_PORT_LEN];
	int port;
	long int first_seen;
	long int last_seen;
	pthread_rwlock_t rwlock;
	UT_hash_handle hh;
};

struct nbs_list {
	struct nb_info *list;
	unsigned short int num_nbs;
	pthread_rwlock_t rwlock;
};


#endif