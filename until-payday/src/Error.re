type error = {message: string};

let genericError = {message: "An issue occured"};

let notFoundError = {message: "We could not find your .paydayrc file!"};

let fileNotFound = message =>
  Js.String.indexOf("no such file or directory", message) > (-1);

let checkErrorMessage = message =>
  fileNotFound(message) ? notFoundError : genericError;