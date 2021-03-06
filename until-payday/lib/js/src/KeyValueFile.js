// Generated by BUCKLESCRIPT VERSION 4.0.5, PLEASE EDIT WITH CARE
'use strict';

var Fs = require("fs");
var List = require("bs-platform/lib/js/list.js");
var $$Array = require("bs-platform/lib/js/array.js");
var Caml_array = require("bs-platform/lib/js/caml_array.js");
var Caml_format = require("bs-platform/lib/js/caml_format.js");

function validContent(line) {
  return line.indexOf("=") > -1;
}

function parseLine(acc, line) {
  var parsedLine = line.split("=");
  if (parsedLine.length === 2) {
    return List.concat(/* :: */[
                acc,
                /* :: */[
                  /* :: */[
                    /* record */[
                      /* key */Caml_array.caml_array_get(parsedLine, 0),
                      /* value */Caml_format.caml_float_of_string(Caml_array.caml_array_get(parsedLine, 1))
                    ],
                    /* [] */0
                  ],
                  /* [] */0
                ]
              ]);
  } else {
    return acc;
  }
}

function formatFileContent(fileContent) {
  return List.fold_left(parseLine, /* [] */0, $$Array.to_list(fileContent.split("\n")));
}

function paydayFile(configPath) {
  return formatFileContent(Fs.readFileSync(configPath, "utf8"));
}

exports.validContent = validContent;
exports.parseLine = parseLine;
exports.formatFileContent = formatFileContent;
exports.paydayFile = paydayFile;
/* fs Not a pure module */
