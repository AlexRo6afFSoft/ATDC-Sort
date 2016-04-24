//TODO: Make sorting of more than one elements possible
function __merge(what, b1, e1, b2, e2, comp) {
    var __arr = [];
    var it1 = b1
        , it2 = b2;
    while (it1 != e1 && it2 != e2) {
        if (comp(what[it1], what[it2]) == 1) {
            __arr[__arr.length] = what[it1];
            it1++;
        } else if (comp(what[it1], what[it2]) == 2) {
            __arr[__arr.length] = what[it2];
            it2++;
        }
    }

    if (it1 == e1) {
        while (it2 != e2) {
            __arr[__arr.lenght] = what[it2];
            it2++;
        }
    } else if (it2 == e2) {
        while (it1 != e1) {
            __arr[__arr.lenght] = what[it1];
            it1++;
        }
    }

    it1 = b1;
    for (var i = 0; i < e1 - b1 + 1; i++) {
        what[it1] = __arr[i];
        it1++;
    }

    it2 = b2;
    for (var i = e1 - b1 + 1; i < __arr.length; i++) {
        what[it2] = __arr[i];
        it2++;
    }
}

function __atdc_sort(what, Begin, End, comp) {
    var dist = End - Begin + 1;
    if (dist == 0)
        return;
    if (dist == 1)
        return;
    if (dist == 2) {
        var last = End - 1;
        var b = what[Begin];
        if (comp(what[Begin], what[last]) == 2) {
            what[Begin] = what[last];
            what[last] = b;
        }
        return;
    }

    dist /= 2;
    var mid = Begin + dist;
    __atdc_sort(what, Begin, mid, comp)
    __atdc_sort(what, mid, End, comp);
    __merge(what, Begin, mid, mid, End, comp);
}

function atdc_sort(what, Begin, End, comp) {
    if (comp == undefined) {
        comp = function (a, b) {
            if (a < b) {
                return 1;
            } else {
                return 2;
            }
        }
    }
    __atdc_sort(what, Begin, End, comp);
}

if (exports) {
    exports.atdc_sort = atdc_sort;
}