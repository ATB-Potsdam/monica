#!/usr/bin/python
# -*- coding: ISO-8859-15-*-

import sys
#sys.path.append('')	 # path to monica_python.pyd or monica_python.so
import monica_python
import json

def main():

	with open("../sim.json") as f:
		sim = json.load(f)

	with open("site-soil-profile-from-db.json") as f:
		site = json.load(f)

	with open("../crop.json") as f:
		crop = json.load(f)

	sim["path-to-output"] = "."
	sim["include-file-base-path"] = "../../../"
	sim["climate.csv"] = "../climate.csv"
	site["SiteParameters"]["SoilProfileParameters"][1]["id"] = 2
	
	#print "startDate: " + sim["start-date"]
	#print "sim: " + json.dumps(sim)

	results = monica_python.runMonica({
		"sim-json-str" : json.dumps(sim),
		"site-json-str" : json.dumps(site),
		"crop-json-str" : json.dumps(crop)
	})

	print json.loads(results["run"])
		
main()
