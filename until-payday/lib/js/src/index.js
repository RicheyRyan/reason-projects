// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

var Fs          = require("fs");
var Js_exn      = require("bs-platform/lib/js/js_exn.js");
var Process     = require("process");
var Caml_array  = require("bs-platform/lib/js/caml_array.js");
var Caml_format = require("bs-platform/lib/js/caml_format.js");

var today = new Date();

var currentYear = today.getUTCFullYear();

function numDayOfDate(date) {
  return date.getUTCDate();
}

function monthOfDate(d) {
  return d.getUTCMonth() + 1.0;
}

function daysInMonth(year, month) {
  return new Date(year, month, 0.0).getDate();
}

function daysLeftInMonth(daysSoFar, monthDays) {
  return monthDays - daysSoFar;
}

var match = Process.env["HOME"];

var home = match !== undefined ? match : "";

var configPath = "" + (String(home) + "/.paydayrc");

var genericError = /* record */[/* message */"An issue occured"];

var notFoundError = /* record */[/* message */"We could not find your .paydayrc file!"];

function fileNotFound(message) {
  return +(message.indexOf("no such file or directory") > -1);
}

function checkErrorMessage(message) {
  var match = fileNotFound(message);
  if (match !== 0) {
    return notFoundError;
  } else {
    return genericError;
  }
}

function desiredContent(message) {
  return +(message.indexOf("PAYDAY_DATE") > -1);
}

function paydayValue(paydayFile) {
  return Caml_format.caml_float_of_string(Caml_array.caml_array_get(paydayFile.split("="), 1));
}

function daysUntilPayday(payday, today) {
  var numToday = today.getUTCDate();
  var numDays = payday - numToday;
  var days = numDays > 0.0 ? numDays : daysInMonth(currentYear, today.getUTCMonth() + 1.0) - numToday + payday;
  var outputDays = days | 0;
  return "There are " + (String(outputDays) + " days until payday");
}

var result;

try {
  result = Fs.readFileSync(configPath, "utf8");
}
catch (raw_exn){
  var exn = Js_exn.internalToOCamlException(raw_exn);
  if (exn[0] === Js_exn.$$Error) {
    var match$1 = exn[1].message;
    result = match$1 !== undefined ? checkErrorMessage(match$1)[/* message */0] : "An issue occured";
  } else {
    throw exn;
  }
}

var match$2 = desiredContent(result);

var outputString = match$2 !== 0 ? daysUntilPayday(paydayValue(result), today) : result;

console.log(outputString);

exports.today             = today;
exports.currentYear       = currentYear;
exports.numDayOfDate      = numDayOfDate;
exports.monthOfDate       = monthOfDate;
exports.daysInMonth       = daysInMonth;
exports.daysLeftInMonth   = daysLeftInMonth;
exports.home              = home;
exports.configPath        = configPath;
exports.genericError      = genericError;
exports.notFoundError     = notFoundError;
exports.fileNotFound      = fileNotFound;
exports.checkErrorMessage = checkErrorMessage;
exports.desiredContent    = desiredContent;
exports.paydayValue       = paydayValue;
exports.daysUntilPayday   = daysUntilPayday;
exports.result            = result;
exports.outputString      = outputString;
/* today Not a pure module */