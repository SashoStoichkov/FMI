// ============================================================================

var array = [10, 80, 30, 90, 40, 50, 70];

function quickSort(array) {
  if (array.length <= 1) {
    return array;
  }

  var pivot = array[0];
  var left = [];
  var right = [];

  for (var i = 1; i < array.length; i++) {
    if (array[i] < pivot) {
      left.push(array[i]);
    } else {
      right.push(array[i]);
    }
  }

  return quickSort(left).concat(pivot, quickSort(right));
}

console.log(quickSort(array));

// ============================================================================

function elInArray(el, arr) {
  for (var i = 0; i < arr.length; i++) {
    if (arr[i] === el) {
      return true;
    }
  }

  return false;
}

function expressionResult(expr) {
  expr = expr.split(" ");

  while (expr.length > 1) {
    if (elInArray("*", expr)) {
      var iOp = expr.indexOf("*");
      expr.splice(
        iOp - 1,
        3,
        (parseInt(expr[iOp - 1]) * parseInt(expr[iOp + 1])).toString()
      );
    } else if (elInArray("/", expr)) {
      var iOp = expr.indexOf("/");

      if (parseInt(expr[iOp + 1]) === 0) {
        console.log(
          "Apparently your math teacher never told you that you can't divide by 0. But probably they have, so you haven't listen! Overall - you can't divide by 0. I'm so happy that you learned something new today :)"
        );
        break;
      } else {
        expr.splice(
          iOp - 1,
          3,
          (parseInt(expr[iOp - 1]) / parseInt(expr[iOp + 1])).toString()
        );
      }
    } else if (!elInArray("*", expr) && !elInArray("/", expr)) {
      switch (expr[1]) {
        case "+":
          expr.splice(0, 3, (parseInt(expr[0]) + parseInt(expr[2])).toString());
          break;

        case "-":
          expr.splice(0, 3, (parseInt(expr[0]) - parseInt(expr[2])).toString());
          break;

        default:
          break;
      }
    }
  }

  return expr[0];
}

var input = process.argv[2];
console.log(input);

var maxOperations = 0;
var validOperations = 0;

var expr = input.split("=");

for (var i = 0; i < expr.length; i++) {
  expr[i] = expr[i].trim();
}

maxOperations = expr.length - 1;

for (var i = 0; i < expr.length && i != expr.length - 1; i++) {
  if (expressionResult(expr[i]) === expressionResult(expr[i + 1])) {
    validOperations++;
  }
}

console.log(validOperations + " / " + maxOperations);

// ============================================================================
