var results = [];

var sum = function (x, y) {
  console.log("Computing...");
  return x + y;
};

function arrAreEqual(arr1, arr2) {
  if (arr1.length != arr2.length) {
    return false;
  } else {
    for (var i = 0; i < arr1.length; i++) {
      if (arr1[i] != arr2[i]) {
        return false;
      }
    }

    return true;
  }
}

function dejavu(args) {
  for (var i = 0; i < results.length; i++) {
    if (arrAreEqual(results[i].getArgs(), args)) {
      return results[i].getRes();
    }
  }

  return false;
}

function memorize(f) {
  return function () {
    var args = [].slice.call(arguments);

    if (dejavu(args)) {
      return dejavu(args);
    }

    var result = f.apply(undefined, args);

    results.push({
      args: args,
      res: result,
      getArgs: function () {
        return this.args;
      },
      getRes: function () {
        return this.res;
      },
    });

    return result;
  };
}

var memSum = memorize(sum);
console.log(memSum(2, 3));
console.log(memSum(3, 3));
console.log(memSum(2, 3));

// ============================================================================

function trippleAdd(a, b, c) {
  return a + b + c;
}

function curry(f) {
  var accArgs = [];
  return function helper() {
    var args = [].slice.call(arguments);
    for (var i = 0; i < args.length; i++) {
      accArgs.push(args[i]);
    }

    if (accArgs.length < f.length) {
      return helper;
    } else {
      var res = f.apply(undefined, accArgs);
      accArgs = [];
      return res;
    }
  };
}

var cTrippleAdd = curry(trippleAdd);

console.log(cTrippleAdd(1)(2)(3));
console.log(cTrippleAdd(1, 2)(3));
console.log(cTrippleAdd(1, 2, 3));

// ============================================================================

function compose() {
  var fns = [].slice.call(arguments).reverse();

  return function (x) {
    fns.forEach(function (fn) {
      x = fn(x);
    });

    return x;
  };
}

var addOne = (x) => x + 1;
var sqrt = (x) => x * x;
var log = (x) => console.log(x);

addOneSqrtLog = compose(log, sqrt, addOne);

addOneSqrtLog(1); // 4

// ============================================================================
