/* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this
* file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/*
Authors:
Michael Berg <michael.berg@zalf.de>

Maintainers:
Currently maintained by the authors.

This file is part of the MONICA model.
Copyright (C) Leibniz Centre for Agricultural Landscape Research (ZALF)
*/

#ifndef MONICA_ENV_JSON_FROM_JSON_CONFIG_H
#define MONICA_ENV_JSON_FROM_JSON_CONFIG_H

#include <string>

#include "tools/date.h"
#include "run-monica.h"
#include "json11/json11.hpp"
#include "json11/json11-helper.h"

namespace Monica
{
	Tools::EResult<json11::Json> findAndReplaceReferences(const json11::Json& root, 
																												const json11::Json& j);

  json11::Json createEnvJsonFromJsonStrings(std::map<std::string, std::string> params);

  json11::Json createEnvJsonFromJsonObjects(std::map<std::string, json11::Json> params);
}

#endif //MONICA_ENV_FROM_JSON_H
