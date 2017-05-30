const basePaste = 11.4;
const squareDiscount = 1;
const vtb = 0.5
const onlyTwoDocs = 0.5;
const kVTB = 1 / 12;
const k1VTB = 1.6;
const minPaste = 10.4;
const costFrom = 3000000;
const pasteFrom = 600000;

let currentPaste = basePaste;
let currentPriceFlat = costFrom;
let currentPricePaste = 0;

$(document).ready(function() {

  $("#callform").submit(function() {
  var th = $(this);
  $.ajax({
    type: "POST",
    url: "cgi-bin/forms.php",
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
      if (currentPaste  > minPaste && currentPaste  + squareDiscount > minPaste) {
          currentPaste -= squareDiscount;
          $("#paste_current").html(currentPaste);
      }
    } else {
      currentPaste += squareDiscount;
      $("#paste_current").html(currentPaste);
    }
  });

  $("#vtbcard").on("click", function() {
    if ($(this).is(":checked")) {
      if (currentPaste > minPaste && currentPaste + vtb > minPaste) {
        currentPaste -= vtb;
        $("#paste_current").html(currentPaste);
      }
    } else {
      currentPaste += vtb;
      $("#paste_current").html(currentPaste);
    }
  });

  $("#twodoc").on("click", function() {
    if ($(this).is(":checked")) {
        if (currentPaste > minPaste && currentPaste + vtb > minPaste) {
          currentPaste += onlyTwoDocs;
          $("#paste_current").html(currentPaste);
        }
    } else {
      currentPaste -= onlyTwoDocs;
      $("#paste_current").html(currentPaste);
    }
  });


  $("#app_cost").bind("change", function(e) {
    currentPriceFlat = $("#app_cost").val();
    $("#sizeCredit").html((String(currentPriceFlat - currentPricePaste).replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 ')) + " <span>&#8381;</span>");
  });

  $("#paste").bind("change", function(e) {
    currentPricePaste = $("#paste").val();
    $("#sizeCredit").html((String(currentPriceFlat - currentPricePaste).replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 ')) + " <span>&#8381;</span>");
  });



  $("#period").bind('change', function(e) {
    let summCredit = parseFloat($("#app_cost").val());
    let creditTerm = parseFloat($("#period").val());
    let currentPaste1 = parseInt(currentPaste);

    let payment = Math.abs(MonthlyPayment(summCredit, creditTerm, currentPaste));
    let MustMonthly = Math.abs(mustMonthlyIncome(payment));

     payment /= 10;
     MustMonthly /= 10;

    $("#post_period").html(payment.toString().split('.')[0].replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 ') + " <span>&#8381;</span>");
    $("#must_payment").html(MustMonthly.toString().split('.')[0].replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 ') + " <span>&#8381;</span>");
  });




  let summCredit = parseFloat($("#app_cost").val());
  let creditTerm = parseFloat($("#period").val());
  let currentPaste1 = parseInt(currentPaste);

  let payment = Math.abs(MonthlyPayment(summCredit, creditTerm, currentPaste));
  let MustMonthly = Math.abs(mustMonthlyIncome(payment));

   payment /= 10;
   MustMonthly /= 10;

  $("#post_period").html(payment.toString().split('.')[0].replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 ') + " <span>&#8381;</span>");
  $("#must_payment").html(MustMonthly.toString().split('.')[0].replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 ') + " <span>&#8381;</span>");


    $("#paste_current").html(currentPaste);
});



let MonthlyPayment = function(summCredit, creditTerm, currentPaste) {
  console.log(summCredit + "sum");
  console.log(currentPaste  + 'kp');
  console.log(kVTB);
    console.log(-creditTerm);
	return (summCredit * kVTB * currentPaste) / (1 - Math.pow(1 + kVTB * currentPaste), -creditTerm);
}

let mustMonthlyIncome = function(monthlyPayment) {
	return monthlyPayment * k1VTB;
}
