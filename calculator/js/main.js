const basePaste = 11; //базовая ставка
const squareDiscount = 1; // Зависимость от площади квартиры
const vtb = 0.5; // Завсимость от зп в ВТБ
const onlyTwoDocs = 0.5; // Зависимость от количесва документов
const kVTB = 1 / 12; // Коэффициент ВТБ
const k1VTB = 1.6; // Коэффициент ВТБ
const minPaste = 10.4; // Минимальная ставка
const costFrom = 3000000; //Минимальный размер кредита
const pasteFrom = 600000; // Минимальный первоначальный взнос

let currentPaste = basePaste; // Текущая ставка
let currentPriceFlat = costFrom; // Текущая цена
let currentPricePaste = 0; // Текущий размер кредита

$(document).ready(function () {

    $("#callform").submit(function () {
        var th = $(this);
        $.ajax({
            type: "POST",
            url: "/realty_calculator_submit",
            data: th.serialize()
        }).done(function () {
            $("#myModal").modal('hide');
            alert("Заявка отправлена! В ближайшее время с вами свяжется специалист банка")
        });
        return false;
    });


    let a = $("#paste").ionRangeSlider({
        min: 270000,
        max: 9400000,
        from: pasteFrom,
        step: 10000,
        grid: true,
        postfix: "  руб",
        onStart: function (data) {
            $('#result-paste').html(String(data.from).replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 '));
            makeParams();
            //console.log(data);
        },
        onChange: function (data) {
            $('#result-paste').html(String(data.from).replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 '));
            makeParams();
        },
        onFinish: function (data) {
            $('#result-paste').html(String(data.from).replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 '));
            makeParams();

        },
        onUpdate: function (data) {
            $('#result-paste').html(String(data.from).replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 '));
            makeParams();

        }
    });

    let test = $('#paste').data('ionRangeSlider');


    $("#app_cost").ionRangeSlider({
        min: 1800000,
        max: 10000000,
        from: costFrom,
        step: 50000,
        grid: true,
        postfix: " руб",
        onStart: function (data) {
            $('#result-app_cost').html(String(data.from).replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 '));
            makeParams();
        },
        onChange: function (data) {
            $('#result-app_cost').html(String(data.from).replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 '));

            //test.is_update = true;
            test.update({
              from: data.from * 0.15,
            });

            //test.labels.p_from_fake = data.from * 0.15;

            console.log(test);

        },
        onFinish: function (data) {
            $('#result-app_cost').html(String(data.from).replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 '));
            makeParams();
        },
        onUpdate: function (data) {
            $('#result-app_cost').html(String(data.from).replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 '));
            makeParams();
        },
    });

    $("#period").ionRangeSlider({
        min: 1,
        max: 30,
        from: 10,
        step: 1,
        grid: true,
        postfix: " лет",
        onStart: function (data) {
            $('#result-period').html(data.from);
        },
        onChange: function (data) {
            $('#result-period').html(data.from);
        },
        onFinish: function (data) {
            $('#result-period').html(data.from);
        },
        onUpdate: function (data) {
            $('#result-period').html(data.from);
        }
    });

    $("#sizeCredit").html((String(costFrom - pasteFrom).replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 ')) + " <span>&#8381;</span>")

    $("#area").on("click", function () {
        if ($(this).is(":checked")) {
            $('.shadow').css('display', 'block');
            if (currentPaste > minPaste && currentPaste + squareDiscount > minPaste) {
                currentPaste -= squareDiscount;
                if (currentPaste <= 10) {
                    currentPaste = 10;
                }
                if (($('#vtbcard').is(":checked")) && ($('#twodoc').is(":checked"))) {
                    currentPaste += vtb;
                }
                $("#paste_current").html(currentPaste + " <span>%</span>");
                makeParams();
            }
        } else {

            if (($('#twodoc').is(":checked"))) {
                $('.shadow').css('display', 'block');
            } else {
                $('.shadow').css('display', 'none');
            }

            currentPaste += squareDiscount;
            if (($('#vtbcard').is(":checked"))) {
                currentPaste = 10.9;
            }
            $("#paste_current").html(currentPaste + " <span>%</span>");
            makeParams();
        }
    });

    $("#vtbcard").on("click", function () {
        if ($(this).is(":checked")) {
            if (currentPaste > minPaste && currentPaste + vtb > minPaste) {
                currentPaste -= vtb;
                $("#paste_current").html(currentPaste + " <span>%</span>");
                makeParams();
            }
        } else {
            currentPaste += vtb;
            $("#paste_current").html(currentPaste + " <span>%</span>");
            makeParams();
        }
    });

    $("#twodoc").on("click", function () {
        if ($(this).is(":checked")) {
            $('.shadow').css('display', 'block');
            if (currentPaste >= minPaste && currentPaste + vtb > minPaste) {
                currentPaste += onlyTwoDocs;
                if ($('#vtbcard').is(":checked")) {
                    currentPaste -= currentPast;
                }
                if (($('#vtbcard').is(":checked")) && ($('#area').is(":checked"))) {
                    currentPaste = 10;
                }

                $("#paste_current").html(currentPaste + " <span>%</span>");
                makeParams();
            }
        } else {
            if (($('#area').is(":checked"))) {
                $('.shadow').css('display', 'block');
            } else {
                $('.shadow').css('display', 'none');
            }
            if (($('#vtbcard').is(":checked")) && ($('#twodoc').is(":checked"))) {
                currentPaste += vtb;
            }
            currentPaste += onlyTwoDocs;
            $("#paste_current").html(currentPaste + " <span>%</span>");
            makeParams();
        }
    });


    $("#app_cost").bind("change", function (e) {
        currentPriceFlat = $("#app_cost").val();
        $("#sizeCredit").html((String(currentPriceFlat - currentPricePaste).replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 ')) + " <span>&#8381;</span>");

        makeParams();


    });

    $("#paste").bind("change", function (e) {
        currentPricePaste = $("#paste").val();
        $("#sizeCredit").html((String(currentPriceFlat - currentPricePaste).replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 ')) + " <span>&#8381;</span>");

        makeParams();
    });


    $("#period").bind('change', function (e) {
        let summCredit = parseFloat($("#app_cost").val());
        let creditTerm = parseFloat($("#period").val());
        let currentPaste1 = parseInt(currentPaste);

        let payment = Math.abs(MonthlyPayment(summCredit, creditTerm, currentPaste));
        let MustMonthly = Math.abs(mustMonthlyIncome(payment));

        //  payment /= 10;
        //  MustMonthly /= 10;
        $("#post_period").html(payment.toString().split('.')[0].replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 ') + " <span>&#8381;</span>");
        $("#must_payment").html(MustMonthly.toString().split('.')[0].replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 ') + " <span>&#8381;</span>");
    });


    let summCredit = parseFloat($("#app_cost").val());
    let vznos = parseFloat($("#paste").val());
    let creditS = summCredit - vznos;
    let creditTerm = parseFloat($("#period").val());
    let currentPaste1 = parseInt(currentPaste);

    let payment = Math.abs(MonthlyPayment(creditS, creditTerm, currentPaste));
    let MustMonthly = Math.abs(mustMonthlyIncome(payment));

    //  payment /= 10;
    //  MustMonthly /= 10;

    $("#post_period").html(payment.toString().split('.')[0].replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 ') + " <span>&#8381;</span>");
    $("#must_payment").html(MustMonthly.toString().split('.')[0].replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 ') + " <span>&#8381;</span>");


    $("#paste_current").html(currentPaste + " <span>%</span>");
});

let makeParams = function () {
    let summCredit = parseFloat($("#app_cost").val());
    let creditTerm = parseFloat($("#period").val());
    let currentPaste1 = parseInt(currentPaste);

    let payment = Math.abs(MonthlyPayment(summCredit, creditTerm, currentPaste));
    let MustMonthly = Math.abs(mustMonthlyIncome(payment));


    //  payment /= 10;
    //  MustMonthly /= 10;
    $("#post_period").html(payment.toString().split('.')[0].replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 ') + " <span>&#8381;</span>");
    $("#must_payment").html(MustMonthly.toString().split('.')[0].replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 ') + " <span>&#8381;</span>");
    //console.log($('#paste').val()*0.15);
};


let MonthlyPayment = function (summCredit, creditTerm, currentPaste) {
    var creditTermM = creditTerm * 12;
    let currentCredit = summCredit - parseInt($("#paste").val());
    var newCurrentPaste = currentPaste / 1200;
    return (parseInt(currentCredit) * (newCurrentPaste / (1 - (Math.pow(1 + newCurrentPaste, -creditTermM)))));


};

let mustMonthlyIncome = function (monthlyPayment) {
    return monthlyPayment * k1VTB;
};
