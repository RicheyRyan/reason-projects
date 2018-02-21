// Generated by BUCKLESCRIPT VERSION 2.2.0, PLEASE EDIT WITH CARE
'use strict';

var Unit$GearUtil = require("./Unit.bs.js");

var partial_arg = Unit$GearUtil.Distance[/* convert */6];

function metreToKm(param) {
  return partial_arg(/* Metre */0, /* Km */1, param);
}

var partial_arg$1 = Unit$GearUtil.Distance[/* convert */6];

function metreToMile(param) {
  return partial_arg$1(/* Metre */0, /* Mile */2, param);
}

var partial_arg$2 = Unit$GearUtil.Time[/* convert */8];

function minuteToHour(param) {
  return partial_arg$2(/* Minute */4, /* Hour */3, param);
}

function distancePerMinute(cadence, development) {
  return cadence * development;
}

function distancePerHour(cadence, development) {
  return minuteToHour(cadence * development);
}

function cadenceToSpeedKm(cadence, metresOfDevelopment) {
  var development = metreToKm(metresOfDevelopment);
  return minuteToHour(cadence * development);
}

function cadenceToSpeedMiles(cadence, metresOfDevelopment) {
  var development = metreToMile(metresOfDevelopment);
  return minuteToHour(cadence * development);
}

exports.metreToKm = metreToKm;
exports.metreToMile = metreToMile;
exports.minuteToHour = minuteToHour;
exports.distancePerMinute = distancePerMinute;
exports.distancePerHour = distancePerHour;
exports.cadenceToSpeedKm = cadenceToSpeedKm;
exports.cadenceToSpeedMiles = cadenceToSpeedMiles;
/* No side effect */
