// Generated by BUCKLESCRIPT VERSION 4.0.5, PLEASE EDIT WITH CARE
'use strict';


function numDayOfDate(date) {
  return date.getUTCDate();
}

function monthOfDate(date) {
  return date.getUTCMonth() + 1.0;
}

function daysInMonth(year, month) {
  return new Date(year, month, 0.0).getDate();
}

function daysLeftInMonth(daysSoFar, monthDays) {
  return monthDays - daysSoFar;
}

exports.numDayOfDate = numDayOfDate;
exports.monthOfDate = monthOfDate;
exports.daysInMonth = daysInMonth;
exports.daysLeftInMonth = daysLeftInMonth;
/* No side effect */
