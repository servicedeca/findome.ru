const basePaste = 11.4; //базовая ставка
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

$(document).ready(function() {

  $("#callform").submit(function() {
  var th = $(this);
  $.ajax({
    type: "POST",
    url: "/cgi-bin/forms.php",
    data: th.serialize()
  }).done(function() {
    $("#myModal").modal('hide');
    alert("Заявка отправлена!")
  });
  return false;
});


  $("#app_cost").ionRangeSlider({
      min: 1800000,
      max: 10000000,
      from: costFrom,
      step: 50000,
			grid: true,
      postfix: " руб",
			onStart: function (data) {
					$('#result-app_cost').html(String(data.from).replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 '));
			},
			onChange: function (data) {
					$('#result-app_cost').html(String(data.from).replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 '));
			},
			onFinish: function (data) {
						$('#result-app_cost').html(String(data.from).replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 '));
			},
			onUpdate:function (data) {
						$('#result-app_cost').html(String(data.from).replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 '));
			}
  });

  $("#paste").ionRangeSlider({
      min: 600000,
      max: 3400000,
      from: pasteFrom,
      step: 100000,
			grid: true,
      postfix: "  руб",
			onStart: function (data) {
					$('#result-paste').html(String(data.from).replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 '));
			},
			onChange: function (data) {
					$('#result-paste').html(String(data.from).replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 '));
			},
			onFinish: function (data) {
						$('#result-paste').html(String(data.from).replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 '));
			},
			onUpdate:function (data) {
						$('#result-paste').html(String(data.from).replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 '));
			}
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
			onUpdate:function (data) {
					$('#result-period').html(data.from);
			}
  });

    $("#sizeCredit").html((String(costFrom-pasteFrom).replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 ')) + " <span>&#8381;</span>")

  $("#area").on("click", function() {
    if ($(this).is(":checked")) {
      $('.shadow').css('display', 'block');
      if (currentPaste  > minPaste && currentPaste  + squareDiscount > minPaste) {
          currentPaste -= squareDiscount;
          if (currentPaste <= 10.4){
            currentPaste = 10.4;
          }
          $("#paste_current").html(currentPaste + " <span>%</span>");
          makeParams();
      }
    } else {

      if(($('#twodoc').is(":checked"))){
        $('.shadow').css('display', 'block');
      } else {
        $('.shadow').css('display', 'none');
      }

      currentPaste += squareDiscount;
      if (($('#vtbcard').is(":checked"))){
        currentPaste = 10.9;
      }
      $("#paste_current").html(currentPaste + " <span>%</span>");
      makeParams();
    }
  });

  $("#vtbcard").on("click", function() {
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

  $("#twodoc").on("click", function() {
    if ($(this).is(":checked")) {
            $('.shadow').css('display', 'block');
        if (currentPaste >= minPaste && currentPaste + vtb > minPaste) {
          currentPaste += onlyTwoDocs;
          $("#paste_current").html(currentPaste + " <span>%</span>");
          makeParams();
        }
    } else {
      if(($('#area').is(":checked"))){
        $('.shadow').css('display', 'block');
      } else {
        $('.shadow').css('display', 'none');
      }
      currentPaste -= onlyTwoDocs;
      $("#paste_current").html(currentPaste + " <span>%</span>");
      makeParams();
    }
  });


  $("#app_cost").bind("change", function(e) {
    currentPriceFlat = $("#app_cost").val();
    $("#sizeCredit").html((String(currentPriceFlat - currentPricePaste).replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 ')) + " <span>&#8381;</span>");

    makeParams();
  });

  $("#paste").bind("change", function(e) {
    currentPricePaste = $("#paste").val();
    $("#sizeCredit").html((String(currentPriceFlat - currentPricePaste).replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 ')) + " <span>&#8381;</span>");

    makeParams();
  });



  $("#period").bind('change', function(e) {
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

let makeParams = function() {
    let summCredit = parseFloat($("#app_cost").val());
    let creditTerm = parseFloat($("#period").val());
    let currentPaste1 = parseInt(currentPaste);

    let payment = Math.abs(MonthlyPayment(summCredit, creditTerm, currentPaste));
    let MustMonthly = Math.abs(mustMonthlyIncome(payment));

    //  payment /= 10;
    //  MustMonthly /= 10;
    $("#post_period").html(payment.toString().split('.')[0].replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 ') + " <span>&#8381;</span>");
    $("#must_payment").html(MustMonthly.toString().split('.')[0].replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 ') + " <span>&#8381;</span>");
};


let MonthlyPayment = function(summCredit, creditTerm, currentPaste) {
  var creditTermM = creditTerm * 12 ;
  console.log(creditTermM);
  let currentCredit = summCredit - parseInt($("#paste").val());
  var newCurrentPaste = currentPaste / 1200;
  console.log(currentCredit + 'Текущий размер кредмта')
  console.log(newCurrentPaste);
  console.log(summCredit  + "вот оно");
  console.log(summCredit * (newCurrentPaste / (1 - (Math.pow(1 + newCurrentPaste, -creditTermM)))) + 'число');
  return (parseInt(currentCredit) * (newCurrentPaste / (1 - (Math.pow(1 + newCurrentPaste, -creditTermM)))));
}

let mustMonthlyIncome = function(monthlyPayment) {
	return monthlyPayment * k1VTB;
}
