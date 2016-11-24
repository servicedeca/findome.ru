(function ($) {

    Drupal.ajax.prototype.commands.reloadPage = function() {
        window.location.reload();
    }

    var addHtmlInfoApartment = function(response, classModal){

        var object = jQuery.parseJSON(response);
        $('.'+classModal+' #apt-num').html(object.apt_number);
        if (object.status == 1) {
            $('.'+classModal+' #apt-status').html("");
        } else {
            $('.'+classModal+' #apt-status').html("Забронирована");
        }
        $('.'+classModal+' #developer').html(object.developer);
        $('.'+classModal+' #complex').html(object.complex);
        $('.'+classModal+' #address').html(object.address);
        $('.'+classModal+' #type').html(object.rooms+" комнатная");
        $('.'+classModal+' #floor').html(object.floor);
        $('.'+classModal+' #section').html(object.section);
        $('.'+classModal+' #sq').html(object.sq);
        $('.'+classModal+' #deadline').html(object.deadline);
        $('.'+classModal+' #sq-live').html(object.sq_live);
        if(object.cost) {
            $('.'+classModal+' #cost').html(object.cost.replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 '));
        }
        else {
            $('.'+classModal+' #cost').html('0');
        }
        if(object.price) {
            $('.'+classModal+' #price').html(object.price.replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 '));
        }
        else {
            $('.'+classModal+' #price').html('0');
        }
        $('.'+classModal+' .modal-flat-plane').html(object.img_plan);
        $('.goto-flat').attr('onclick', 'window.open(\''+object.path+'\')');

        $('.'+classModal+' #id_comparison').html(object.add_comparison);
        $('.'+classModal+' #id_booking').html(object.booking);
        $('.'+classModal+' #id_get_id').html(object.get_id);
    };

    function getUrlVar(){
        var urlVar = window.location.search; // получаем параметры из урла
        var arrayVar = []; // массив для хранения переменных
        var valueAndKey = []; // массив для временного хранения значения и имени переменной
        var resultArray = []; // массив для хранения переменных
        arrayVar = (urlVar.substr(1)).split('&'); // разбираем урл на параметры
        if(arrayVar[0]=="") return false; // если нет переменных в урле
        for (i = 0; i < arrayVar.length; i ++) { // перебираем все переменные из урла
            valueAndKey = arrayVar[i].split('='); // пишем в массив имя переменной и ее значение
            resultArray[valueAndKey[0]] = valueAndKey[1]; // пишем в итоговый массив имя переменной и ее значение
        }
        return resultArray; // возвращаем результат
    }


    Drupal.behaviors.realtyInit = {
        attach: $(function() {

            $(document).ready(function() {
                try {
                    $.browserSelector();
                    if($("html").hasClass("chrome")) {
                        $.smoothScroll();
                    }

                    function post(path, params, method) {
                        method = method || "post"; // Set method to post by default if not specified.

                        // The rest of this code assumes you are not using a library.
                        // It can be made less wordy if you use one.
                        var form = document.createElement("form");
                        form.setAttribute("method", method);
                        form.setAttribute("action", path);

                        for(var key in params) {
                            if(params.hasOwnProperty(key)) {
                                var hiddenField = document.createElement("input");
                                hiddenField.setAttribute("type", "hidden");
                                hiddenField.setAttribute("name", key);
                                hiddenField.setAttribute("value", params[key]);

                                form.appendChild(hiddenField);
                            }
                        }

                        document.body.appendChild(form);
                        form.submit();
                    }
                    var tid = '', cid = '', context = '';

                    /*          $('.ui.selection.dropdown').dropdown({
                     onChange: function(val) {

                     var id = val.split('-');
                     if (id[0] == 'tid') {
                     tid = id[1];
                     } else if (id[0] == 'cid') {
                     cid = id[1];

                     $('#search_submit').removeAttr('data-toggle');
                     $('#search_submit').removeAttr('data-target');

                     Drupal.attachBehaviors();
                     }
                     }
                     });*/

                    $('.selectpicker').on('change', function(){
                        var val = $(this).find("option:selected").data('value');
                        var id = val.split('-');
                        if (id[0] == 'tid') {
                            tid = id[1];
                        } else if (id[0] == 'cid') {
                            cid = id[1];

                            $('.search_submit').removeAttr('data-toggle');
                            $('.search_submit').removeAttr('data-target');

                            Drupal.attachBehaviors();
                        }
                    });

                    /*          $('.ui.menu .ui.dropdown').dropdown({
                     on: 'hover',
                     });*/

                    $('.search_submit').on('click', function () {
                        if (cid != '') {
                            $.cookie('cityId', cid, {
                                expires: 365,
                                path: '/'
                            });

                            console.log(tid);
                            post('/search/' + cid, {type: tid}, 'get');
                        }
                    });

                    $('.city-submit').on('click', function () {
                        var cid = $(this).data('cid');

                        $.cookie('cityId', cid, {
                            expires: 365,
                            path: '/'
                        });

                        if (context == 'mainSearchCon') {
                            if (tid != '') {
                                post('/search/' + cid, {type: tid}, 'get');
                            } else {
                                post('/search/' + cid);
                            }
                        } else if (context == 'developerCon') {
                            post('/developers/city/' + cid);
                        } else if (context == 'complexCon') {
                            post('/complexes/city/' + cid);
                        } else if (context == 'searchCon') {
                            post('/search/' + cid);
                        } else if (context == 'mortageCon'){
                            post('/mortgage/city/' + cid);
                        } else {
                            post('/taxonomy/term/' + cid);
                        }
                    });

                    $('.contextCtr').on('click', function () {
                        context = $(this).data('context');
                    })

                } catch(err) {};
            });

            setTimeout(function(){
                $('#hellopreloader_preload').fadeOut('0',function() {
                    //$(this).remove();
                });
            }, 10);

            // Обработка ошибок
            window.onerror = function(message, url, lineNumber) {
                console.log("fadeOut");
                $('#hellopreloader_preload').fadeOut('0',function() {
                    //$(this).remove();
                });
            };


            // $('#views-exposed-form-map-map-city #edit-field-area-tid option[value=23]').attr('selected', 'selected');
            // jQuery.extend(Drupal.settings, {"devel":{"request_id":149027}});
            window.alert = function(arg) { if (window.console && console.log) { console.log(arg);}};
            if(Drupal.settings.id) {
                $("body").attr("id","index");

            }
            if(Drupal.settings.issue) {
                $("body").attr("id", Drupal.settings.issue);
            }

            if(Drupal.settings.about) {
                $("body").attr("id", Drupal.settings.about);
            }
            if(Drupal.settings.front) {
                $("body").attr("id", Drupal.settings.front);
            }

            if(Drupal.settings.planComplex) {
                for(var i in Drupal.settings.planComplex) {
                    $('.floor-'+Drupal.settings.planComplex[i]+' #'+i).attr('class', 'floor-plan booking-apartment-svg');
                    console.log(Drupal.settings.planComplex);
                }
            }
            /*
             $(window).load(function(){
             $('#hellopreloader_preload').fadeOut('0',function(){$(this).remove();});
             });
             */




            //Открыть модальное окно бронирования
            var getParam = getUrlVar();
            if (getParam['booking']) {
                $('.apartment-booking-but').trigger('click');
            }
            if(getParam['pass-reset-token']) {
                $('#edit-profile').trigger('click');
            }
        })
    };

    Drupal.behaviors.realtyChecboxModal = {
        attach: $(function() {
            // чек бокс для модалки
            $(document).ready(function(){
                // проверяем, какие чекбоксы активны и меняем сласс для родительского дива

                $('.modal_checkbox').each(function() {
                    var checkbox = $(this).find('input[type=checkbox]');
                    if(checkbox.prop("checked")){
                        $(this).addClass("check_active_modal");
                    }
                });

                // при клике по диву, делаем проверку
                $(document).on('click', 'div .modal_checkbox', function() {

                    var checkbox = $(this).find('input[type=checkbox]');
                    // если чекбокс был активен
                    if(checkbox.prop("checked")){
                        // снимаем класс с родительского дива
                        $(this).removeClass("check_active_modal");

                        // и снимаем галочку с чекбокса
                        checkbox.prop("checked", false);
                        // если чекбокс не был активен
                    }else{
                        // добавляем класс родительскому диву
                        $(this).addClass("check_active_modal");
                        // ставим галочку в чекбоксе
                        checkbox.prop("checked", true);
                    }
                });
            });
        })
    }

    Drupal.behaviors.realtyTooltip = {
        attach: $(function () {

            $('[rel="tooltip"]').tooltip({

            })

            $(document).ajaxSuccess(function() {
                $('[rel="tooltip"]').tooltip({

                })
            })
        })
    }

    Drupal.behaviors.realtyBlockComplex = {
        attach: $(function (context, settings) {

            $(document).on('click', '.next-complex', function() {
                var nextComplex = $(this).attr('data-nid-complex');
                var city = $('.next-complex').data('tid-city');

                $.ajax({
                    url: '/get_next_complex',
                    type: 'POST',
                    crossDomain: true,
                    data: {
                        nid: nextComplex,
                        city: city
                    },
                    success: function(response) {
                        if(response) {
                            var complex = jQuery.parseJSON(response);

                            console.log(complex);

                            $('#realty-logo-complex').hide()
                                .html(complex.logo)
                                .fadeToggle(1000);

                            $('#realty-image-complex').hide()
                                .html(complex.image)
                                .fadeToggle(1000);

                            $('#realty-title-complex').html(complex.title);
                            $('#realty-slogan-complex').html(complex.slogan);
                            $('#realty-details-complex').html(complex.details);
                            $('#realty-plan-complex').html(complex.plan);
                            $('#realty-apartment-complex').html(complex.apartment);
                            $('#realty-price-complex').html(complex.price);
                            $('#realty-floor-complex').html(complex.floor);
                            $('#realty-developer-complex').html(complex.developer);
                            $('#next').attr('data-nid-complex', complex.next);
                            $('#prev').attr('data-nid-complex', complex.prev);
                        }
                    },
                    error: function(response) {
                        alert('false');
                    }
                });
            });
        })
    }

    Drupal.behaviors.realtyFormSearchGetParam = {
        attach: $(function () {
            if (Drupal.settings.get) {
                if (Drupal.settings.get.area) {
                    $.each(Drupal.settings.get.area, function(key, val){
                        $('.area-'+val).trigger('click');
                    });
                }
                if (Drupal.settings.get.developer) {
                    $.each(Drupal.settings.get.developer, function(key, val){
                        $('.developer-'+val).trigger('click');
                    });
                }
                if (Drupal.settings.get.category) {
                    $.each(Drupal.settings.get.category, function(key, val){
                        $('.room-'+val).trigger('click');
                    });
                }
                if (Drupal.settings.get.complex) {
                    $.each(Drupal.settings.get.complex, function(key, val){
                        $('.complex-'+val).trigger('click');
                    });
                }
                if (Drupal.settings.get.metro) {
                    $.each(Drupal.settings.get.metro, function(key, val){
                        $('.metro-'+val).trigger('click');
                    });
                }
            }
        })
    };


    Drupal.behaviors.realtySearchMap = {
        attach: $(function () {

            function complex_select_map(devid) {
                var city = Drupal.settings.city;
                $.ajax({
                    url: '/get_developer_complex',
                    type: 'POST',
                    data: {
                        developer: devid,
                        city: city,
                        map: 1
                    },
                    success: function(response) {
                        var object = jQuery.parseJSON(response);
                        console.log(object);
                        $('.modal-map-complex .list-modal-city').html('');
                        $('.modal-map-complex .list-modal-city').html(object.modal);
                        $('#edit-field-home-complex-target-id').html('');
                        if (object != null) {
                            console.log(object.modal);
                            $('.modal-map-complex .list-modal-city').html(object.modal);
                            $('#edit-field-home-complex-target-id').html(object.select);
                        }
                    },
                    error: function(response) {
                        alert('false');
                    }
                });
            }

            // чек бокс для фильтров
            $(document).ready(function(){

                // проверяем, какие чекбоксы активны и меняем класс для родительского дива
                $('.mfilter_checkbox').each(function(){
                    var checkbox = $(this).find('input[type=checkbox]');
                    if(checkbox.prop("checked")) $(this).addClass("mfilter_checkbox_active");
                });

                // при клике по диву, делаем проверку
                $('.mfilter_checkbox').click(function(){
                    var checkbox = $(this).find('input[type=checkbox]');

                    // если чекбокс был активен
                    if(checkbox.prop("checked")){

                        // снимаем класс с родительского дива
                        $(this).removeClass("mfilter_checkbox_active");

                        // и снимаем галочку с чекбокса
                        checkbox.prop("checked", false);

                        // если чекбокс не был активен
                    }else{

                        // добавляем класс родительскому диву
                        $(this).addClass("mfilter_checkbox_active");

                        // ставим галочку в чекбоксе
                        checkbox.prop("checked", true);
                    }
                });
            });

        })
    };

    Drupal.behaviors.complexInfo = {
        attach: $(function () {
            var Circle = function(sel) {
                var circles = document.querySelectorAll(sel);
                [].forEach.call(circles, function (el) {
                    var valEl = parseFloat(el.innerHTML);
                    valEl = valEl * 1258 / 100;
                    el.innerHTML = '<svg width="500" height="500"><circle transform="rotate(-90)" r="200" cx="-240" cy="210" /><circle transform="rotate(-90)" style="stroke-dasharray:' + valEl + 'px 1258px;" r="200" cx="-240" cy="210" /></svg>';
                });
            };
            Circle('.cir');
        })
    }



    Drupal.behaviors.realtyPlanComplex = {
        attach: $(function(){
            var imgArrowGray = '/'+Drupal.settings.REALTY_FRONT_THEME_PATH+'/images/arrow-gray.svg';
            var imgLinkActive = '/'+Drupal.settings.REALTY_FRONT_THEME_PATH+'/images/cmp_hover.svg';

            // Получение информации о квартире
            var getNidApartment = function(home, floor, apartment){
                $.ajax({
                    url: '/mark_picture_get_nid_apartment',
                    type: 'POST',
                    async: false,
                    data: {
                        home: home,
                        floor: floor,
                        apartment: apartment
                    },
                    success: function(response) {
                        if(response) {
                            $('#plan-modal-trigger').trigger('click');
                            addHtmlInfoApartment(response, 'plan_modal');
                        }
                    },
                    error: function(response) {
                        alert('false');
                    }
                });
            };

            // Получение плана ЖК
            var getComplexPlan = function(complexid) {
                $.ajax({
                    url: '/realty_complex_plan_get_complex_plan',
                    type: 'POST',
                    async: false,
                    data: {
                        complex_id: complexid
                    },
                    success: function(response) {
                        if(response) {
                            var object = JSON.parse(response);

                            $('#svg-plan').html(object.complex);
                            addClassApartment(object);
                        }
                    },
                    error: function(response) {
                        alert('false');
                    }
                });
            }

            // Получение плана
            var getFloorPlan = function(home_id, section_id, floor, home_flag, link_floor, apt_id) {
                var plan,
                    home_number,
                    data = {
                        home_id: home_id
                    };

                floor ? data.floor = floor: data;
                section_id ? data.section_id = section_id: data;
                home_flag ? data.home_flag = home_flag: data;
                link_floor ? data.link_floor = link_floor: data;
                apt_id ? data.apt_id = apt_id: data;

                $.ajax({
                    url: "/realty_complex_plan_get_home_id",
                    type: 'POST',
                    async: false,
                    data: data,
                    success: function(response) {
                        if(response) {
                            var object = JSON.parse(response);
                            if (object.home_plan) {
                                $('#svg-plan').html(object.home_plan);
                                plan = 'home' + '-' + object.home_number;
                            }

                            if(object.floor_plan) {
                                //console.clear();
                                //console.log(object);
                                $('#svg-plan').html(object.floor_plan);
                                if(object.floor_link){
                                    $('#floors-link').html(object.floor_link);
                                    //.show();
                                }
                                $('#svg-legend').show();
                                $('#current_floor').html('Этаж <br><span>' + object.current_floor + '</span>');
                                plan = 'floor' + '-' + object.home_number + '-' + object.section_number;
                            }
                            addClassApartment(object);
                        }

                        //событи навеления на этаж для вывода активных квартир
                        $('.link-floor').hover(function() {
                            var link = $(this);
                            var floor = $(this).data('floor');
                            var home = $(this).data('home');
                            var section = new String($(this).data('section'));
                            if(section.indexOf('_') != -1) {
                                section = section.replace(/\_/gi, '.');
                            }
                            $.ajax({
                                url: '/realty_complex_plan_get_count_ap_floor',
                                type: 'POST',
                                async: false,
                                data: {
                                    home: home,
                                    section: section,
                                    floor: floor
                                },
                                success: function(response) {
                                    if(response) {
                                        link.attr('data-original-title', response+' кв. в продаже');
                                        console.log(link.attr('data-original-title'));
                                    }
                                },
                                error: function(response) {
                                    alert('false');
                                }
                            });
                        });

                    },
                    error: function(response) {
                        alert('false');
                    }
                });
                return plan;
            };

            var addClassApartment = function(object) {
                if (object.complex) {

                    var complexId = $('#nav-complex-plan').data('complex_id');

                    var oldClass = $('#complex-'+complexId+'-home-'+Drupal.settings.current_home_id).attr('class');
                    $('#complex-'+complexId+'-home-'+Drupal.settings.current_home_id).attr('class', oldClass + ' apt_active');

                }
                if (object.apartment_book) {

                    for(var i in object.apartment_book) {
                        $('#'+i).attr('class', 'floor-plan booking-apartment-svg');
                    }
                }
                if (object.apartment_active) {
                    for(var i in object.apartment_active) {
                        $('#'+i).attr('class', 'floor-plan active-apartment-svg');
                    }
                }

                if (object.home_plan) {// @todo Нужно переделать!
                    if (Drupal.settings.current_section_id) {
                        var section = Drupal.settings.current_section_id.replace(/\./gi, "_");

                        var complexId = $('#nav-complex-plan').data('complex_id');

                        for (var i = 0; i < 20; i++) {
                            if ($('#'+i+'-complex-'+complexId+'-home-'+Drupal.settings.current_home_id+'-section-'+section).length >0){

                                var oldClass = $('#'+i+'-complex-'+complexId+'-home-'+Drupal.settings.current_home_id+'-section-'+section).attr('class');
                                $('#'+i+'-complex-'+complexId+'-home-'+Drupal.settings.current_home_id+'-section-'+section).attr('class', oldClass + ' apt_active');
                            }
                        }
                    }

                } else if (object.current_apartment) {

                    var oldClass = $('#'+object.current_apartment).attr('class');
                    $('#'+object.current_apartment).attr('class', oldClass + ' apt_active');
                }
            };

            // Выбор дома на странице квартиры
            $(document).on('click', '#get-plan-complex', get_plan_complex = function() {

                $('#nav-complex-plan').removeClass('active');
                var alink = $('#nav-complex-plan').find('a');
                alink.attr ('not-allowed');
                alink.attr ('title', '');

                $('#nav-floor-plan').addClass('active');
                var alink = $('#nav-floor-plan').find('a');
                alink.removeClass ('not-allowed');
                alink.attr ('title', '');

                var complexId = $(this).data('id-complex');

                var result = getFloorPlan(Drupal.settings.current_home_id, Drupal.settings.current_section_id.replace(/\./gi, "_"), Drupal.settings.current_floor_value, '', '', Drupal.settings.current_apartment_id);
                var result_mass = result.split('-');
                var plan = result_mass[0];
                var home_number = result_mass[1];
                var section_number = result_mass[2];

                if (result_mass[2] != 'false') {
                    var section = result_mass[2].replace(/\_/gi, ".");

                    $('#nav-home-plan').html('<a class="back-home-plan"><label style="padding-top:15px;">Секция <br>№<span> '+section+'</span></label></a>');

                    $('#nav-home-plan').removeClass('active');
                    var alink = $('#nav-home-plan').find('a');
                    alink.removeClass ('not-allowed');
                    alink.addClass ('back-home-plan ');
                    alink.attr ('title', '');
                }

                var section = section_number.replace(/\_/gi, ".");

                $('#nav-complex-plan').html('<a class="back-complex-plan"><label style="padding-top:15px;">Дом <br>№<span> '+home_number+'</span></label></a>');

                //$('#svg-plan').height('550px');
            })


            // После выбора дома
            $(document).on('click', '#svg-plan .complex-plan', function(){

                var homeId = $(this).attr('id'),
                    homeId = homeId.split('-'),
                    plan, home_number, result_mass,
                    result = getFloorPlan(homeId[3], '', '', true);

                result_mass = result.split('-');
                plan = result_mass[0];
                home_number = result_mass[1];

                // Если в доме есть секции
                if (plan == 'home') {
                    $('#nav-complex-plan').removeClass('active');
                    $('#nav-complex-plan').html('<a class="back-complex-plan"><label style="padding-top:15px;">Дом <br>№<span> '+home_number+'</span></label></a>');

                    $('#nav-home-plan').html('<a class="back-home-plan"><label style="padding-top:15px;">Секция</label><img src='+imgLinkActive+' class="triangle-active"/></a>');

                    $('#nav-home-plan').addClass('active');
                    $('#nav-home-plan').attr('data-home_id', homeId[3]);

                    var link = $('#nav-home-plan').find('a[class=not-allowed]');
                    link.removeClass('not-allowed');

                    var alink = $('#nav-floor-plan').find('a');
                    alink.addClass('not-allowed');
                    alink.attr('title', "Выберите секцию");

                    $('#floors-link').html('<li style="padding-right: 30px">Выберите секцию</li>');
                }

                // Если в доме нет секций
                if (plan == 'floor') {
                    console.log('floor');
                    $('#nav-complex-plan').removeClass('active');
                    $('#nav-complex-plan').html('<a class="back-complex-plan"><label style="padding-top:15px;">Дом <br>№<span> '+home_number+'</span></label></a>');

                    var alink = $('#nav-floor-plan').find('a');
                    alink.removeClass('not-allowed');
                    alink.attr('title', "");

                    $('#nav-floor-plan').addClass('active');

                    //$('#svg-plan').height('550px');

                    //$('#floors-link').html('<li style="padding-right: 30px">Выберите этаж</li>');
                }
            });

            // После выбора секции
            $(document).on('click', '.home-plan', function(){
                var id = $(this).attr('id');
                id = id.split('-');
                var home_id = id[4];
                var section_id = id[6];
                var section = section_id.replace(/\_/gi, ".");

                getFloorPlan(home_id, section_id, '', '', '',Drupal.settings.current_apartment_id);
                $('#nav-home-plan').removeClass('active');
                $('#nav-home-plan').html('<a class="back-home-plan"><label style="padding-top:15px;">Секция <br>№<span> '+section+'</span></label></a>');
                $('#nav-floor-plan').addClass('active');

                var alink = $('#nav-floor-plan').find('a');
                alink.attr('title', "");

                var link = $('#nav-floor-plan').find('a[class=not-allowed]');
                link.removeClass('not-allowed');

                //$('#svg-plan').height('550px');
            });

            // После выбора квартиры
            $(document).on('click','.floor-plan', function(){
                var homeId,
                    apartment,
                    floor = $('.number-floor-active a').data('floor'),
                    apartments = $(this).attr('id').split('-');

                for(var i in apartments){
                    if (i == 0){
                        homeId = apartments[i];
                        continue;
                    }
                    else {
                        for (var j in apartments[i]){
                            if (apartments[i].split('_')[1] == floor) {
                                apartment = apartments[i].split('_')[0];
                                break;
                            }
                        }
                    }
                }
                if (apartment) {
                    getNidApartment(homeId, floor, apartment);
                }
            })

            // Ссылка выбора этажа
            $(document).on('click', '.link-floor', function(){
                var home_id = $(this).data('home'),
                    section_id = $(this).data('section'),
                    floor = $(this).data('floor'),
                    plan;

                //var section = section_id.replace(/\./gi, "_");
                getFloorPlan(home_id, section_id, floor, '', '', Drupal.settings.current_apartment_id ? Drupal.settings.current_apartment_id: '');

                //$('#svg-plan').height('550px');
            });

            // Ссылка на выбор дома
            $(document).on('click', '.back-complex-plan', back_complex_plan = function(){
                var complex_id = $('#nav-complex-plan').data('complex_id');
                getComplexPlan(complex_id);

                $('#nav-complex-plan').addClass('active');

                $('#nav-home-plan').removeClass('active');
                $('#nav-floor-plan').removeClass('active');
                $('#floors-link').html('<li style="padding-right: 30px">Выберите дом, чтобы узнать о количестве и планировках квартир в продаже</li>');
                $('#svg-legend').hide();
                $('#current_floor').html('Этаж');

                $('#nav-complex-plan').html('<a><label style="padding-top:15px;">Дом</label><img src='+imgLinkActive+' class="triangle-active"/></a>');
                $('#nav-home-plan').html('<a><label style="padding-top:15px;">Секция</label></a>');

                var alink = $('#nav-home-plan').find('a');
                alink.addClass('not-allowed');
                alink.attr('title', "Выберите дом");

                var alink = $('#nav-floor-plan').find('a');
                alink.addClass('not-allowed');
                alink.attr('title', "Выберите дом");

                $('#svg-plan').height('');
            });

            //Ссылка на выбор секции
            $(document).on('click', '.back-home-plan', function(){
                var home_id = Drupal.settings.current_home_id ? Drupal.settings.current_home_id : $('#nav-home-plan').data('home_id'),
                    plan, home_number, result_mass,
                    result = getFloorPlan(home_id, '', '', true);

                result_mass = result.split('-');
                plan = result_mass[0];
                home_number = result_mass[1];

                if (plan == 'home') {
                    $('#nav-floor-plan').removeClass('active');

                    var alink = $('#nav-floor-plan').find('a');
                    alink.addClass('not-allowed');
                    alink.attr('title', "Выберите дом");

                    $('#nav-home-plan').html('<a><label style="padding-top:15px;">Секция</label><img src='+imgLinkActive+' class="triangle-active"/></a>');
                    $('#nav-home-plan').addClass('active');
                    $('#floors-link').html('<li style="padding-right: 30px">Выберите секцию</li>');
                    $('#svg-legend').hide();
                    $('#current_floor').html('Этаж');

                    var link = $('#nav-home-plan').find('a[class=not-allowed]');
                    link.removeClass('not-allowed');

                    var alink = $('#nav-floor-plan').find('a');
                    alink.addClass('not-allowed');
                    alink.attr('title', "Выберите секцию");
                }
                $('#svg-plan').height('');
            });

            var get_block_plan_complex = function () {
                $.ajax({
                    url: '/get_block_plan_complex',
                    type: 'GET',
                    data: {
                        nid: Drupal.settings.complex_nid
                    },
                    success: function(response) {

                    },
                    error: function(response) {

                    }
                });
            }

            if (Drupal.settings.apartment_plan_callback == true) {
                get_plan_complex();
            }

            /**
             * Если нет плана жк
             */

            if (Drupal.settings.complex_plan_none == true) {
                var result = getFloorPlan(Drupal.settings.home_tid, '', '', true);

                if (result != undefined) {

                    var result_mass = result.split('-');
                    var plan = result_mass[0];
                    var home_number = result_mass[1];

                    // Если в доме есть секции
                    if (plan == 'home') {
                        $('#nav-complex-plan').html('<a><label style="padding-top:15px;">Дом <br>№<span> '+home_number+'</span></label></a>');

                        $('#nav-home-plan').html('<a class="back-home-plan"><label style="padding-top:15px;"></label><img src='+imgLinkActive+' class="triangle-active"/></a>');

                        $('#nav-home-plan').addClass('active');
                        $('#nav-home-plan').attr('data-home_id', Drupal.settings.home_tid);

                        var link = $('#nav-home-plan').find('a[class=not-allowed]');
                        link.removeClass('not-allowed');

                        var alink = $('#nav-floor-plan').find('a');
                        alink.addClass('not-allowed');
                        alink.attr('title', "Выберите секцию");
                    }
                }
            }

            /*** Выплывающие окна с информацией ***/

            var queueNotify;
            var homeNotify;

            var prePoligon;
            var preHome = 0;
            var preSection = 0;
            var homesInfo = {};
            var sectionInfo = {};
            var notifyHomeShow = false;
            var notifyRefreshing = false;

            // Обновление окна с информацией
            var notifyUpdate = function (homeId) {

                // Если наводка на доме
                if (homesInfo[homeId] != undefined) {
                    var homeInfo = homesInfo[homeId];
                    var apartmentHome = homeInfo['apartments'];
                }
                // Если наводка на секции
                else {
                    var homeInfo = sectionInfo[homeId];
                    var apartmentHome = homeInfo['apartments'];

                    var section = true;
                }

                var countApartment, countApartmentStudio;
                var apartmentTypes = ['1', '1с', '2', '2с', '3', '3с'];

                // Обновление основной информации о доме

                // Если это секция
                if (section) {
                    $('#home_number').html(homeId);
                    $('#object_title').html('Секция');
                    $('#home_queue').html(homeInfo['section_queue'] ? homeInfo['section_queue'] : '1');
                    $('#home_floors').html(homeInfo['section_floor'] ? homeInfo['section_floor'] : homeInfo['floors']);
                    $('#home_deadline').html(homeInfo['section_deadline']);
                    $('#home_readiness').attr('style', homeInfo['section_readiness'] ? 'width:' +  homeInfo['section_readiness'] +'%;' : 'width:' +  10 +'%;');
                    $('#home_readiness_title').html(homeInfo['section_readiness'] ? homeInfo['section_readiness'] + '%' : 10 + '%');

                }
                // Если это дом
                else {
                    $('#home_number').html(homeInfo['number']);
                    $('#object_title').html('Дом');
                    $('#home_queue').html(homeInfo['queue'] ? homeInfo['queue'] : '1');
                    $('#home_floors').html(homeInfo['floors']);
                    $('#home_deadline').html(homeInfo['deadline_quarter'] + ' квартал 20' + homeInfo['deadline_year']);
                    $('#home_readiness').attr('style', homeInfo['readiness'] ? 'width:' +  homeInfo['readiness'] +'%;' : 'width:' +  10 +'%;');
                    $('#home_readiness_title').html(homeInfo['readiness'] ? homeInfo['readiness'] + '%' : 10 + '%');

                }

                // Обнуление количества квартир в окне с информацией
                $.each (apartmentTypes, function (index, value) {
                    $('#apt_'+index+'_count').html('0');
                })

                $('#apt_active_count').html(apartmentHome['active_count']);
                $('#apt_total_count').html(apartmentHome['total_count']);

                // Обновление информации о количестве квартир
                $.each(apartmentHome, function (index, value) {

                    if ($('#apt_'+value['rooms']+'_count').length > 0) {
                        $('#apt_'+value['rooms']+'_count').html(value['count'] ? value['count'] : 0);
                        $('#apt_'+value['rooms']+'_total').html(value['total'] ? value['total'] : 0);
                    }
                })

                // Запись поличества квартир другого типа
                $('#apt_otherc_count').html(countApartmentStudio);
                $('#apt_other_count').html(countApartment);

                notifyRefreshing = false;
            }

            // При выборе дома
            $(document).on('click', '.complex-plan', function() {
                // Скрытие всплавающей подсказки
                homeNotify = setTimeout(function(){
                    $(".floatingmes").css("display", "none");
                },100);

                notifyRefreshing = false;
            })

            // При выборе секции дома
            $(document).on('click', '.home-plan', function () {
                // Скрытие всплавающей подсказки
                homeNotify = setTimeout(function(){
                    $(".floatingmes").css("display", "none");
                },100);

                notifyRefreshing = false;
            })

            // При наводке на дом
            $(document).on({
                mouseenter: function () {
                    clearTimeout(homeNotify);

                    // Обновление окна с информацией о квартире
                    var homeId = $(this).attr('id').split('-')[3];
                    if (homesInfo[homeId] != undefined) {

                        notifyUpdate(homeId);
                    }

                    $(".floatingmes").css("display", "inline");
                },
                mouseleave: function () {
                    homeNotify = setTimeout(function(){
                        $(".floatingmes").css("display", "none");
                    },100)
                }
            }, '.complex-plan');

            if (Drupal.settings.bug_fix == true) {
                bugTopX = 3200;
                console.log('ok');
            } else {
                bugTopX = 390;
            }


            // При движении по дому
            $(document).on({
                mousemove: function (pos) {
                    var homeId = $(this).attr('id').split('-')[3];

                    // Если инфорация в окне инфорации не соответствует дому
                    if (preHome != homeId) {

                        // Если информация о доме отсутствует
                        if (homesInfo[homeId] == undefined && !notifyRefreshing) {
                            notifyRefreshing = true;

                            $.ajax({
                                url: '/get_info_home',
                                type: 'GET',
                                data: {
                                    tid: homeId
                                },
                                success: function(response) {

                                    // Запись инфорации о доме в общий массив
                                    homesInfo[homeId] = JSON.parse(response);

                                    // Обновление окна с информацией о квартире
                                    notifyUpdate(homeId);
                                },
                                error: function(response) {
                                    alert('false');
                                }
                            });
                        }
                        // Если информация о доме имеется
                        else {

                            // Если информация еще не получена
                            if (homesInfo[homeId] == undefined) {

                                // @todo Вывод окна с прогресбаром

                            }
                            // Если инфорация получена
                            else {

                                // Обновление окна с информацией о квартире
                                notifyUpdate(homeId);
                            }
                        }
                    }

                    // Запись id дома информация о котором отображена в окне
                    preHome = homeId;

                    $(".floatingmes").css('left',(pos.pageX+30)+'px').css('top',(pos.pageY-bugTopX)+'px');
                }
            }, ".complex-plan");

            // При наводке на секцию дома
            $(document).on({
                mouseenter: function () {
                    $(".floatingmes").css("display", "inline");
                },
                mouseleave: function () {
                    $(".floatingmes").css("display", "none");
                }
            }, ".home-plan");

            // При движении по секции дома
            $(document).on({
                mousemove: function (pos) {

                    var homeId = $(this).attr('id').split('-')[4];
                    var sectionNumber = $(this).attr('id').split('-')[6].replace(/\_/gi, ".");

                    // Если инфорация в окне инфорации не соответствует дому
                    if (preSection != sectionNumber) {

                        // Если информация о доме отсутствует
                        if (sectionInfo[sectionNumber] == undefined && !notifyRefreshing) {
                            notifyRefreshing = true;

                            $.ajax({
                                url: '/get_info_home',
                                type: 'GET',
                                data: {
                                    tid: homeId,
                                    section: sectionNumber
                                },
                                success: function(response) {

                                    // Запись инфорации о доме в общий массив
                                    sectionInfo[sectionNumber] = JSON.parse(response);

                                    // Обновление окна с информацией о квартире
                                    notifyUpdate(sectionNumber);
                                },
                                error: function(response) {
                                    alert('false');
                                }
                            });
                        }
                        // Если информация о доме имеется
                        else {

                            // Если информация еще не получена
                            if (sectionInfo[sectionNumber] == undefined) {

                                // @todo Вывод окна с прогресбаром

                            }
                            // Если инфорация получена
                            else {

                                // Обновление окна с информацией о квартире
                                notifyUpdate(sectionNumber);
                            }
                        }
                    }

                    // Запись id дома информация о котором отображена в окне
                    preSection = sectionNumber;

                    $(".floatingmes").css('left',(pos.pageX+30)+'px').css('top',(pos.pageY-bugTopX)+'px');
                }
            }, ".home-plan");

            // При наводке на очередь строительства
            $(document).on({
                mouseenter: function () {
                    clearTimeout(queueNotify);

                    $(this).css('opacity', '0.3');
                    $(this).css('fill', '#eeeeee');

                    prePoligon = $(this);

                    $(".tooltip-area").css("display", "inline");
                },
                mouseleave: function () {
                    prePoligon.css('opacity', '');
                    prePoligon.css('fill', '');

                    queueNotify = setTimeout(function () {
                        $(".tooltip-area").css("display", "none");
                        prePoligon = undefined;
                    }, 100);
                }
            }, '.svg-plan-queue');

            // При движении на очереди строительства
            $(document).on({
                mousemove: function (pos) {
                    var quarterNumber = $(this).attr('data-queue'),
                        deadlineQuarter = $(this).attr('data-quarter'),
                        deadlineYear = $(this).attr('data-year');

                    $('#queue_number').html(quarterNumber);

                    if ((deadlineQuarter.length == 0) && (deadlineYear.length == 0)) {
                        $('#deadline').html('сдана');
                    }
                    else {
                        $('#deadline').html(deadlineQuarter + ' квартал ' + deadlineYear + ' год');
                    }

                    $(".tooltip-area").css('left', (pos.pageX + 30) + 'px').css('top', (pos.pageY - bugTopX) + 'px');
                }
            }, ".svg-plan-queue");

            // При движении на пассивном дом
            $(document).on({
                mousemove: function (pos) {
                    if (prePoligon != undefined) {
                        prePoligon.css('opacity', '0.3');
                        prePoligon.css('fill', '#eeeeee');

                        clearTimeout(queueNotify);

                        if (($('#queue_number').html() != '') && ($('#deadline').html != '')) {
                            $(".tooltip-area").css('left', (pos.pageX + 30) + 'px').css('top', (pos.pageY - bugTopX) + 'px');
                        }
                    }
                },
                mouseleave: function () {
                    if (prePoligon != undefined) {
                        prePoligon.css('opacity', '');
                        prePoligon.css('fill', '');

                        queueNotify = setTimeout(function () {
                            $(".tooltip-area").hide();
                        }, 100)
                    }
                }
            }, ".svg-home-passive");
        })
    };

    Drupal.behaviors.realtyPageApatment = {
        attach: $(function() {

            var cvgHover = function() {

                $(".comparisonh").hover(function(){
                    $(this).css("opacity","1");
                    $(".comparison").css("opacity","1");
                });

                $(".comparisonh").mouseout(function(){
                    $(this).css("opacity","0");
                    $(".comparison").css("opacity","0.5");
                });

                $(".bookh").hover(function(){
                    $(this).css("opacity","1");
                    $(".book").css("opacity","1");
                });

                $(".bookh").mouseout(function(){
                    $(this).css("opacity","0");
                    $(".book").css("opacity","0.5");
                });

                $(".pdfh").hover(function(){
                    $(this).css("opacity","1");
                    $(".pdf").css("opacity","1");
                });

                $(".pdfh").mouseout(function(){
                    $(this).css("opacity","0");
                    $(".pdf").css("opacity","0.5");
                });

            };

            cvgHover();
            $(document).ajaxSuccess(function() {
                cvgHover();
            })
        })
    }


    Drupal.behaviors.realtyComplexesFilter = {
        attach: $(function(){

            $('.search-button').click(function(){
                setTimeout(function(){
                    $('#edit-submit-complex').trigger('click');
                },100)
            });

        })
    }

    Drupal.behaviors.realtyGetIdApartment = {
        attach: $(function () {

            $(document).on('click', '#download-id-apartment',function () {
                $('div.realty-preload').show();
                var nid = $(this).data('nid-apartment');
                $.ajax({
                    url: '/get_id_apartment',
                    type: 'GET',

                    data: {
                        nid: nid
                    },
                    success: function(response) {
                        if (response === 'user') {
                            $('.close-modal').trigger('click');
                            $('.head-reg').trigger('click');
                        }
                        else {
                            var link = document.createElement('a');
                            link.href = response;
                            if (link.download !== undefined){
                                var fileName = response.substring(response.lastIndexOf('/') + 1, response.length);
                                link.download = fileName;
                            }
                            if (document.createEvent) {
                                var e = document.createEvent('MouseEvents');
                                e.initEvent('click' ,true ,true);
                                link.dispatchEvent(e);
                                $('div.realty-preload').fadeOut('0',function() {
                                    //$(this).remove();
                                });
                                return true;
                            }
                            var query = '?download';
                            window.open(response + query, '_self');
                        }
                    },
                    error: function(response) {
                        alert('false');
                    }
                });
            });
        })
    }

    Drupal.behaviors.realtyUserProfile = {
        attach: $(function () {
            var getParams = getUrlVar();

            if ((getParams['p'] == 'booking_request_success') ||
                (getParams['p'] == 'mortgage_request_success') ||
                (getParams['p'] == 'booking_mortgage_success') ||
                (getParams['p'] == 'request_not_found')) {

                $(window).load(function(){
                    $('#modal_notify').modal('show');
                });
            }
        })
    }

    Drupal.behaviors.realtyMaterials = {
        attach: $(function () {
            $(".mindic").click(function () {

                var target_id = $(this).data('id');
                $('.mb').hide();

                $('#'+target_id).show();
            });
        })
    }

    Drupal.behaviors.realtyComparison = {
        attach: $(function () {

            var changeAptIdOld;
            var changeAptIdNew;

            if (Drupal.settings.apartments_info) {
                var apartmentsInfo = Drupal.settings.apartments_info;
                var apartmentsInfoKeys = Object.keys(apartmentsInfo);
            }

            var comparisonPrint = function (apartmentsInfoKeys) {

                var i = 0;
                $('#apt-other').html('');

                apartmentsInfoKeys.forEach(function(apartmentNid, apartmentId) {

                    var apartmentInfo = apartmentsInfo[apartmentNid];

                    // Вывод инфорации о первых двух квартирах в массиве
                    if (i < 2) {
                        $('#comparison_apt_'+ i + '.realty-appartment-info').attr('data-id', apartmentInfo.nid);
                        $('#comparison_apt_'+i).find('.apt-change').attr('data-apt-id', apartmentInfo.nid);

                        $('#comparison_apt_'+i).find('.apt-apt').html('<h1 class="realty-appartment-info" data-toggle="modal" data-target=".flat_modal" data-id="'+apartmentInfo.nid+'">Квартира<span>'+apartmentInfo.number+'</span></h1>');
                        $('#comparison_apt_'+i).find('.apt-plan').html(apartmentInfo.plan_300x200);
                        $('#comparison_apt_'+i).find('.apt-status').html(apartmentInfo.status ? '' : 'Забронирована');
                        $('#comparison_apt_'+i).find('.apt-sq').html(apartmentInfo.sq);
                        $('#comparison_apt_'+i).find('.apt-section').html(apartmentInfo.section);
                        $('#comparison_apt_'+i).find('.apt-coast').html(apartmentInfo.coast.replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 '));
                        $('#comparison_apt_'+i).find('.apt-rooms').html(apartmentInfo.rooms+' комнатная');
                        $('#comparison_apt_'+i).find('.apt-complex').html(apartmentInfo.complex);
                        $('#comparison_apt_'+i).find('.apt-floor').html(apartmentInfo.floor);
                        $('#comparison_apt_'+i).find('.apt-price').html(apartmentInfo.price.replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 '));
                        $('#comparison_apt_'+i).find('.apt-material').html(apartmentInfo.material);
                        $('#comparison_apt_'+i).find('.apt-deadline').html(apartmentInfo.deadline_quarter+' квартрал 20'+apartmentInfo.deadline_year);
                        $('#comparison_apt_'+i).find('.apt-ceiling').html(apartmentInfo.ceiling_height);
                        $('#comparison_apt_'+i).find('.apt-parking').html(apartmentInfo.parking ? 'Есть' : 'Нет');
                        $('#comparison_apt_'+i).find('.apt-developer').html(apartmentInfo.developer);
                        $('#comparison_apt_'+i).find('.apt-address').html(apartmentInfo.address);

                        if (apartmentInfo.balkon) {
                            $('#comparison_apt_'+i).find('.apt-balkon').html('Балкон');
                        } else if (apartmentInfo.loggia) {
                            $('#comparison_apt_'+i).find('.apt-balkon').html('Лоджи');
                        } else if (apartmentInfo.balkon_loggia) {
                            $('#comparison_apt_'+i).find('.apt-balkon').html('Балкон + Лоджия');
                        }
                    }
                    // Вывод информации об остальных квартирах
                    else {
                        var imgDelete = '<svg version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" width="12.528px" height="12.528px" viewBox="0 0 12.528 12.528" enable-background="new 0 0 12.528 12.528" xml:space="preserve">' +
                            '<polygon fill="#FFFFFF" points="10.77,0 6.264,4.506 1.759,0 0,1.759 4.506,6.264 0,10.77 1.758,12.528 6.264,8.023 10.77,12.528 12.528,10.77 8.023,6.264 12.528,1.759 		"/>' +
                            '</svg>';

                        var comparisonDelete = '<div class="cross-csi apt-delete delete-apartment-comprassion" data-apartment-nid="'+apartmentInfo.nid+'">'+imgDelete+'</div>';

                        var imgButton = '<svg version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" width="25px" height="7.5px" viewBox="0 0 20.519 6.085" enable-background="new 0 0 20.519 6.085" xml:space="preserve">' +
                            '<polygon fill="#EFEFEF" points="11.352,0 0,3.04 11.352,6.085 11.352,3.75 20.519,3.75 20.519,2.335 11.352,2.335"/>' +
                            '</svg>';

                        var comparisonButton = '<div class="col-xs-2"><div class="compression-button" data-apt-id="'+apartmentInfo.nid+'">'+imgButton+'</div></div>';
                        var aptPlan = '<div  class="col-xs-5">'+apartmentInfo.plan_170x130+'</div>';

                        var aptNumber = '<h1>квартира<span>'+apartmentInfo.number+'</span></h1>';
                        var aptStatus = '<h2>'+apartmentInfo.status ? '' : 'Забронирована'+'</h2>';
                        var aptRoomsSq = '<h3>'+apartmentInfo.rooms+'К&nbsp;&nbsp;<span>'+apartmentInfo.sq+'<span>м<sup>2</sup></h3>';
                        var aptCoast = '<h4>'+apartmentInfo.coast.replace(/(\d)(?=(\d\d\d)+([^\d]|$))/g, '$1 ')+' <span>руб.</span></h4>';
                        var aptComplex = '<p>'+apartmentInfo.complex+'</p>';

                        var aptInfo = '<div class="col-xs-5">'+aptNumber+aptStatus+aptRoomsSq+aptCoast+aptComplex+'</div>';

                        var aptBlock = '<div class="col-xs-12 comprassion-slider-item" id="csi'+apartmentInfo.nid+'">'+
                            comparisonDelete+comparisonButton+aptPlan+aptInfo+
                            '</div>';

                        $('#apt-other').append(aptBlock);
                    }
                    i++;
                })
                Drupal.attachBehaviors();
            }
        })
    }



    Drupal.behaviors.realtyMortgageApartment = {
        attach: $(function () {
            var bankId, cityId, aptId, mortgageId, mortgageCategoryId;

            $(document).on('click', '#realty-bank-info',function () {
                bankId = $(this).data('bank-id');

                $.ajax({
                    url: '/bank_info',
                    type: 'GET',
                    data: {
                        bankId: bankId
                    },
                    success: function(response) {
                        $('#modal_ajax').html('');
                        $('#modal_ajax').html(response);

                        Drupal.attachBehaviors();

                        //$('#realty-mortgage-request-form').ajaxForm();
                        //console.log($('#edit-cities'));
                    },
                    error: function(response) {
                        //    alert('false');
                    }
                });
            });

            $(document).on('click', '#realty-mortgage-info',function () {
                bankId = $(this).data('bank-id');
                mortgageId = $(this).data('mortgage-id');

                $.ajax({
                    url: '/mortgage_info',
                    type: 'GET',
                    data: {
                        bankId: bankId,
                        mortgageId: mortgageId
                    },
                    success: function(response) {
                        $('#modal_ajax').html('');
                        $('#modal_ajax').html(response);

                        Drupal.attachBehaviors();

                        //$('#realty-mortgage-request-form').ajaxForm();
                        //console.log($('#edit-cities'));
                    },
                    error: function(response) {
                        //    alert('false');
                    }
                });
            });

            $(document).on('click', '#realty-mortgage-category-info',function () {
                mortgageCategoryId = $(this).data('mortgage-category-id');

                $.ajax({
                    url: '/mortgage_category_info',
                    type: 'GET',
                    data: {
                        mortgageCategoryId: mortgageCategoryId
                    },
                    success: function(response) {
                        $('#modal_ajax').html('');
                        $('#modal_ajax').html(response);

                        Drupal.attachBehaviors();

                        //$('#realty-mortgage-request-form').ajaxForm();
                        //console.log($('#edit-cities'));
                    },
                    error: function(response) {
                        //    alert('false');
                    }
                });
            });

            $(document).on('click', '#realty-mortgage-apartment',function () {
                aptId = $('#mortgage_block').data('apt-id');
                cityId = $('#mortgage_block').data('city-id');
                bankId = $(this).data('bank-id');
                mortgageId = $(this).data('mortgage-id');

                $.ajax({
                    url: '/mortgage_apartment',
                    type: 'GET',
                    data: {
                        bankId: bankId,
                        aptId: aptId,
                        cityId: cityId,
                        mortgageId: mortgageId
                    },
                    success: function(response) {
                        $('#modal_ajax').html('');
                        $('#modal_ajax').html(response);

                        Drupal.attachBehaviors();

                        $('#realty-mortgage-request-form').ajaxForm();
                        //console.log($('#edit-cities'));
                    },
                    error: function(response) {
                        //    alert('false');
                    }
                });
            });

            $(document).on('change', '#edit-cities', function () {
                var cityId = $(this).val();

                $.ajax({
                    url: '/mortgage_get_affiliate_bank',
                    type: 'GET',
                    data: {
                        bankId: bankId,
                        aptId: aptId,
                        cityId: cityId
                    },
                    success: function(response) {
                        $('#affiliate-box').html(response);
                        Drupal.attachBehaviors();

                    },
                    error: function(response) {
                        //    alert('false');
                    }
                });
            });
        })
    }

    Drupal.behaviors.realtyBookingApartment = {
        attach: $(function () {
            $(document).on('click', '.plupload_start', function(){
                $('.plupload_buttons').show();
            });

            $("#modal-free-not-display-reserveding-apartment").click(function () {
                if ($('.modal_free').length == 0) {
                    $('li .head-reg').trigger('click');
                }
            });


            $('.form-item-payment').click(function() {
                var val = $(this).find('input').val();
                if (val === '2' ) {
                    $('#div-mortgage-applications').show();
                }
                else {
                    $('#div-mortgage-applications').hide();
                }
            });
        })
    };

    Drupal.behaviors.realtyMortgage = {
        attach: $(function () {
            $(document).on('click', '.form-item-mortgage-booking-1', function() {
                var val = $(this).find('input');
                if (val.prop("checked") == true) {
                    $('#mortgage-form-bookings').show();
                }
                else {
                    $('#mortgage-form-bookings').hide();
                }
            });
        })
    };

    Drupal.behaviors.realtyApartmentSignal = {
        attach: $(function () {

            // AJAX download information
            var apartmentPageIconLazy = function() {
                if(Drupal.settings.apartment_page) {
                    var apartmentComparison = $("#id_comparison");
                    var apartmentBooking = $('#booking-button');
                    var apartmentStatus = $('#apart-status');
                    var nid = $('#id_comparison').data('nid-apartment');
                    $.ajax({
                        url: '/realty_apartment_icon_lazy',
                        type: 'POST',
                        data: {
                            nid: nid
                        },
                        success: function(response) {
                            var obj = JSON.parse(response);
                            apartmentComparison.html(obj.button_comparsion);
                            apartmentStatus.html(obj.apart_status);
                            apartmentBooking.html(obj.button_booking);
                        },
                        error: function(response) {
                            alert('false');
                        }
                    });
                }
            }();

            // add to comparison via cookies
            var basketComparison = function(nid) {
                var basket = [];
                var basketStr = $.cookie('comparison');
                if(basketStr) {
                    basket = JSON.parse(basketStr);
                }
                if ($.inArray(nid, basket) == -1) {
                    basket.push(nid);
                }
                basketStr = JSON.stringify(basket);

                $.cookie('comparison', basketStr, {
                    expires: 365,
                    path: '/',
                    domain:'novosibirsk.findome.ru'
                });

                var comparison = $.cookie('comparison');
                console.log(comparison);
            };

            $(".close-notification").click(function(){
                $('.notification-body').hide();
            });

            //Click on Add to Compare
            $(document).on('click', '.apartment-comparison',function () {
                $('div.realty-preload').show();
                var apartment = $(this).parent();
                var nid = $(this).data('node-id');
                var page = $(this).data('page');
                var apart = 0;
                if ($(this).data('apartment') > 0){
                    apart = $(this).data('apartment');
                }
                $.ajax({
                    url: '/apartment_comparison',
                    type: 'POST',
                    data: {
                        nid: nid,
                        apartment: apart,
                        page: page
                    },
                    success: function(response) {
                        basketComparison(nid);
                        if (response) {
                            var comparison = jQuery.parseJSON(response);
                            apartment.html('');
                            apartment.html(comparison['html']);

                            $('.comparisonBlock').attr('class', $('.comparisonBlock').attr('class') + ' m_ap-button-ready');

                            var comprasionCount = Number($('#comprasion_button').attr('data-original-title').replace(/\D+/g,"")) + 1;
                            $('#comprasion_button').attr('data-original-title', 'Квартир в сравнении ('+comprasionCount+')');
                            $('div.realty-preload').fadeOut('0',function() {
                                //$(this).remove();
                            });
                            $('#apt-info').html(comparison['apt_info']);
                            $('#apt-comp-count').html('В списке сравнения добавлено ' + comprasionCount +' квартир(ы)');
                        }
                        else {
                            $('div.realty-preload').fadeOut('0',function() {
                                //$(this).remove();
                            });
                            return 0;
                        }
                        if (comparison['apt_info']) {
                            $('.notification-body').show();
                            console.log(comparison['apt_info'])
                        }

                        console.log(response.html)
                        console.log(response.apt_info)
                        $
                    },
                    error: function(response) {
                        $('div.realty-preload').fadeOut('0',function() {
                            //$(this).remove();
                        });
                        alert('false');
                    }
                });
            });

            // click on the departure signal the git st of reservations
            $(document).on('click', '.apartment-signal',function () {
                $('div.realty-preload').show();
                var apartment = $(this).parent();
                var nid = $(this).data('node-id');
                var apart = 0;
                var page = $(this).data('page');
                if ($(this).data('apartment') > 0){
                    apart = $(this).data('apartment');
                }
                $.ajax({
                    url: '/apartment_signal',
                    type: 'POST',
                    data: {
                        nid: nid,
                        apartment: apart,
                        page: page
                    },
                    success: function(response) {
                        if(response == 'user') {
                            $('.close-modal').trigger('click');
                            $('.head-reg').trigger('click');
                            $('div.realty-preload').fadeOut('0',function() {
                                //$(this).remove();
                            });
                        }
                        if (response != 1 && response != 'user') {
                            apartment.html('');
                            apartment.html(response);
                            $('div.realty-preload').fadeOut('0',function() {
                                //$(this).remove();
                            });
                        }
                        else {
                            $('div.realty-preload').fadeOut('0',function() {
                                //$(this).remove();
                            });
                            return;
                        }
                    },
                    error: function(response) {
                        alert('false');
                    }
                });
            });
        })
    };

    Drupal.behaviors.realtyDynamicallyChange = {
        attach: $(function() {
            var dynamicChange = function() {
                if ($('.big-height').length > 0 && $('.plusplus').length > 0) {
                    $('.big-height').height($('.plusplus').width()/5.7);
                }
                if ($('.big-height').length > 0 && $('.fiftyminus').length > 0) {
                    $('.big-height').height($('.fiftyminus').width()/0.71);
                }
                if ($('.height').length > 0 && $('.fifty').length > 0) {
                    $('.height').height($('.fifty').width()/2.85);
                }
                if ($('.big-height').length > 0 && $('.fiftyplus').length > 0) {
                    $('.big-height').height($('.fiftyplus').width()/2.13);
                }
                if ($('.height').length > 0 && $('.fiftyplus').length > 0) {
                    $('.height').height($('.fiftyplus').width()/4.27);
                }
                if ($('.double-big-height').length > 0 && $('.plusplus').length > 0) {
                    $('.double-big-height').height($('.plusplus').width()/1.89);
                }
                if ($('.triple-big-height').length > 0 && $('.plusplus').length > 0) {
                    $('.triple-big-height').height($('.plusplus').width()/1.41);
                }

                if(document.body.clientWidth <= '1200'){
                    $('div[id="parallax"]').attr('data-type', '');
                    Drupal.attachBehaviors('div[id="paralax"]');
                }
                if(document.body.clientWidth > '1200'){
                    $('div[id="parallax"]').attr('data-type', 'background');
                    Drupal.attachBehaviors('div[id="paralax"]');
                }
            }
            $(document).ready(function(){
                dynamicChange();
            });

            $(window).resize(function() {
                dynamicChange();
            });

            $(document).on('click', '.fotorama__arr--next', function(){
                dynamicChange();
            });
            $(document).on('click', '.fotorama__arr--next', function(){
                dynamicChange();
            });
            $(document).on('click', '.next', function(){
                dynamicChange();
            });
            $(document).on('click', '.prev', function(){
                dynamicChange();
            });
        })
    }

    Drupal.behaviors.realtyFotorama = {
        attach: $(function() {

            function ArrowMeter(){
                var height = $('.height').height();
                $('.fotorama__arr--prev').css('top', height);
                $('.fotorama__arr--next').css('top', height);
            };

            ArrowMeter();

            var $fotoramaDiv = $('#3d').fotorama();
            var fotorama = $fotoramaDiv.data('fotorama');

            $(document).on('click', '.next', function() {
                fotorama.show('>');
                ArrowMeter();
            });
            $(document).on('click', '.prev', function() {
                fotorama.show('<');
                ArrowMeter();
            });

            $(window).load(function(){
                ArrowMeter();
            });

            ArrowMeter();
            $(window).resize(function(){
                ArrowMeter();
            });

        })
    }

    Drupal.behaviors.realtyStickyMenuScroll = {
        attach: $(function() {
            //  sticky menu
            $(window).load(function(){
                $("#header").sticky({ topSpacing: 0, className: 'sticky', wrapperClassName: 'my-wrapper' });
            });

            // jQuery for page scrolling feature - requires jQuery Easing plugin
            $('.page-scroll a').bind('click', function(event) {
                var $anchor = $(this);
                $('html, body').stop().animate({
                    scrollTop: $($anchor.attr('href')).offset().top
                }, 1500, 'easeInOutExpo');
                event.preventDefault();
            });

        })
    }

    Drupal.behaviors.realtyHeaderLoad = {
        attach: $(function () {
            $(window).load(function(){
                if(!Drupal.settings.not_comparison) {
                    $.ajax({
                        url: '/count_comparison',
                        type: 'POST',
                        success: function(response) {
                            $('#comprasion_button').attr('data-original-title', 'Квартир в сравнении ('+response+')');
                        },
                        error: function(response) {
                            alert('false');
                        }
                    });
                }
            });
        })
    }


    Drupal.behaviors.realtySortApartment = {
        attach: $(function() {
            var order = 0;
            var temp_param = 0;
            var param;
            var this_class;

            $(document).ajaxSuccess(function() {
                $(this_class).removeClass('sorting');
                if (temp_param != param) {
                    if (order === 'ASC' || order === 0) {
                        $(this_class).removeClass('sorting');
                        $(this_class).addClass('sorting-up');
                    }
                    else if (order === 'DESC') {
                        $(this_class).removeClass('sorting');
                        $(this_class).removeClass('sorting-down');
                        $(this_class).addClass('sorting-up');
                    }
                }
                else {
                    $(this_class).removeClass('sorting');
                    $(this_class).removeClass('sorting-up');
                    $(this_class).addClass('sorting-down ');
                }
            });

            $(document).on('click', '.sort', function() {
                this_class = $(this);
                param = $(this).data('sort');
                if (temp_param != param) {
                    if (order === 'ASC' || order === 0) {
                        $('#edit-sort-by option[value='+param+']').attr('selected', 'selected');
                        $('#edit-sort-order option[value=ASC]').attr('selected', 'selected');
                        $('#edit-submit-apartments').trigger('click');
                        temp_param = param;
                        $(this).removeClass('sorting');
                        $(this).addClass('sorting-up');
                    }
                    else if (order === 'DESC') {
                        $('#edit-sort-by option[value='+param+']').attr('selected', 'selected');
                        $('#edit-sort-order option[value=DESC]').attr('selected', 'selected');
                        $('#edit-submit-apartments').trigger('click');
                        order = 'ASC';
                        temp_param = 0;
                        $(this).removeClass('sorting');
                        $(this).removeClass('sorting-down');
                        $(this).addClass('sorting-up');
                    }
                }
                else {
                    $('#edit-sort-by option[value='+param+']').attr('selected', 'selected');
                    $('#edit-sort-order option[value=DESC]').attr('selected', 'selected');
                    $('#edit-submit-apartments').trigger('click');
                    order = 'ASC';
                    temp_param = 0;
                    $(this).removeClass('sorting');
                    $(this).removeClass('sorting-up');
                    $(this).addClass('sorting-down ');
                }
            })
            $(document).ajaxSuccess(function() {
                Drupal.attachBehaviors();
            })
        })
    }

    Drupal.behaviors.realtyPlacemarkAddComplex = {
        attach: $(function(){
            $('#edit-field-home-complex-und').change(function() {
            })
        })
    }

    Drupal.behaviors.realtyCommentAJAX = {
        attach: $(function(){
            var complexAssessment = 0;

            $(".top-fng").click(function() {
                $(this).css("fill","#00b7e4");
                $(".bottom-fng").css("fill","#d3d3d3");
                complexAssessment = 1;

            });

            $(".bottom-fng").click(function() {
                $(this).css("fill","#00b7e4");
                $(".top-fng").css("fill","#d3d3d3");

                complexAssessment = -1;
            });

            //при нажатии на ответить
            $(document).on('click', '#answer_comment', function() {
                $('.realty-comment-submit').attr('data-comment-pid',  $(this).data('pid'));
            });

            // Добавление комментария ЖК и застрощика
            $('.realty-comment-submit').click(function() {
                var comment = $('.realty-comment-form-input').val();
                var nid = $(this).data('node-id');
                var pid = $(this).data('comment-pid');

                if(comment != '') {
                    console.log(comment);
                    $.ajax({
                        url: '/realty_add_comment',
                        type: 'POST',
                        data: {
                            comment: comment,
                            nid: nid,
                            assessment: 1,
                            pid: pid ? pid : false,
                            complex_assessment: complexAssessment
                        },
                        success: function(response) {
                            if (response) {

                                $('#info-box')
                                    .html('')
                                    .html('<p class="review-next"> Спасибо Вам! Ваш отзыв будет проверен модератором и опубликован.</p>');
                                $('#like-comment').html('');

                                $('.show-buttom').css("display","none");
                                $('.hide-buttom').css("display","inline");
                            }
                            else {
                                alert(Drupal.t('Error! Contact the administrator of the site.'));
                            }
                        },
                        error: function(response) {
                            alert('false');
                        }
                    });
                }
                else {
                    $('.hint-comment-block')
                        .html('')
                        .html('<p class="textarea-error-text">'+Drupal.t('Write a comment!!')+'</p>');
                    $('.form-control').addClass('textarea-error');
                }
                setTimeout(function(){
                    $('.hint-comment-block').html('')
                    $('.form-control').removeClass('textarea-error');
                },2000);

            });


            // Загрузка комментария о ЖК
            $(document).on('click', '#get_data_comment', function () {
                var cid = $(this).data('cid');

                $.ajax({
                    url: '/get_data_comment',
                    type: 'POST',
                    data: {
                        cid: cid
                    },
                    success: function(response) {
                        var comment = jQuery.parseJSON(response);

                        $('#comment-author').html(comment['author']);
                        $('#comment-text').html(comment['text']);
                    },
                    error: function(response) {
                        alert('false');
                    }
                });
            })

            // Загрузка отзыва о Застройщике
            $(document).on('click', '#get_data_review', function () {
                var nid = $(this).data('nid');

                $.ajax({
                    url: '/get_data_review',
                    type: 'POST',
                    data: {
                        nid: nid
                    },
                    success: function(response) {
                        var review = jQuery.parseJSON(response);

                        $('#review-author').html(review['author']);
                        $('#review-text').html(review['text']);
                    },
                    error: function(response) {
                        alert('false');
                    }
                });
            })
        })
    }

    Drupal.behaviors.realtyGetAppartmentInfoAJAX = {
        attach: $(function(){

            $(document).on('click', '.realty-appartment-info', function(){
                var nid = $(this).data('id');

                $.ajax({
                    url: '/get_appartment_info',
                    type: 'POST',
                    crossDomain: true,
                    data: {
                        nid: nid
                    },
                    success: function(response) {
                        if (response) {

                            addHtmlInfoApartment(response, 'flat_modal');
                        }
                        else {
                            alert(Drupal.t('Error! Contact the administrator of the site.'));
                        }
                    },
                    error: function(response) {
                        alert('false');
                    }
                });



            })
        })
    }

    Drupal.behaviors.realtyPlanComplx = {
        attach: $(function(){
            $(document).on('click', '.need-reg', function(){
                $('.close-modal').trigger('click');
                $('.head-reg').trigger('click');
            })
        })
    }

    Drupal.behaviors.realtyStockFilter = {
        attach: $(function(){
            var developer = $('.Checkbox-developer-stock'),
                select = $('#select-developer');

            function selectDeveloper($this) {
                var tid = $this.val();
                tid = tid.split(';')[0];
                console.log(tid);
                if ($this.prop("checked") == false ) {
                    $('#edit-field-complex-developer-tid option[value='+tid+']').attr('selected', 'selected');
                }
                else {
                    $('#edit-field-complex-developer-tid option[value='+tid+']').attr('selected', false);
                }
            }

            $('.CheckboxDeveloper').click(function(){
                selectDeveloper($(this));
            });

            $('.Checkbox-developer-stock').click(function(){
                selectDeveloper($(this));
            });

            $('.modal_developer .search-button').click(function(){
                setTimeout(function(){
                    $('#edit-submit-stock').trigger('click');
                },100)
            });
        })
    }

    Drupal.behaviors.realtyGallery = {
        attach: $(function(){
            var i = 0;
            while (1) {
                if ($('.may-album-'+i).length > 0) {
                    $('.may-album-'+i).magnificPopup({
                        delegate: 'a',
                        type: 'image',
                        mainClass: 'mfp-img-mobile',
                        gallery: {
                            enabled: true,
                            navigateByImgClick: true,
                            preload: [0,1] // Will preload 0 - before current, and 1 after the current image
                        }
                    });
                    i++;
                    continue;
                } else {
                    break;
                }
            }
            $('.visual-album').magnificPopup({
                delegate: 'a',
                type: 'image',
                mainClass: 'mfp-img-mobile',
                gallery: {
                    enabled: true,
                    navigateByImgClick: true,
                    preload: [0,1] // Will preload 0 - before current, and 1 after the current image
                }
            });
        })
    }

    Drupal.behaviors.realtyComplexStock = {
        attach: $(function(){
            $(document).ready(function() {

                $("#owl-demo").owlCarousel({

                    navigation : true, // Show next and prev buttons
                    slideSpeed : 300,
                    paginationSpeed : 400,
                    singleItem:true

                });
                $('.owl-next').html('');
                $('.owl-prev').html('');
            });
        })
    }

    Drupal.behaviors.realtyAdditionalFieldsPayment = {
        attach: $(function(){
            $('#edit-payment-2').click(function(){
                if ($(this).prop('checked')) {
                    $('.payment-additional-fields').show();
                }
            });
            $('#edit-payment-0').click(function(){
                $('.payment-additional-fields').hide();
            });
            $('#edit-payment-1').click(function(){
                $('.payment-additional-fields').hide();
            });
        })
    }

    Drupal.behaviors.events = {
        attach: function(context, settings) {
            $('body').bind('ajaxSuccess', function(data, status, xhr) {
                alert('ok');
            });
        }
    };


    Drupal.behaviors.realtyRegModal = {
        attach: $(function(){
            $(document).ready(function(){
                $(".reg-item").click(function(){
                    if($(this).attr('class')  ==  'reg-item' ) {
                        $('.reg-item').removeClass('reg-active');
                        $(this).addClass('reg-active');
                    }
                })
            })
        })
    }

    Drupal.behaviors.realtyParallaxComplex = {
        attach: $(function(){

            $('div[data-type="background"]').each(function(){

                $(window).scroll(function() {

                    // вычисляем коэффициент
                    var yPos = -($(window).scrollTop() / $('div[data-type="background"]').data('speed'));

                    // Присваиваем значение background-position
                    var coords = 'center '+ yPos + 'px';

                    // Создаем эффект Parallax Scrolling
                    $('div[data-type="background"]').css({backgroundPosition: coords });

                });
            });
        })
    }

    Drupal.behaviors.realtyComplexApartmentTableHeader = {
        attach: $(function () {
            $(document).ready(function () {
                $("table").stickyTableHeaders();
            });

            $(document).ajaxSuccess(function() {
                $("table").stickyTableHeaders();
            })

        })
    }

    Drupal.behaviors.realtyModalNewsDetails= {
        attach: $(function () {
            var getInfoNew = function(id) {
                $.ajax({
                    url: '/news_details',
                    type: 'POST',
                    data: {
                        nid: id
                    },
                    success: function(response) {
                        if (response) {
                            $('.modal_news').html(response);
                        }
                    },
                    error: function(response) {
                        alert('false');
                    }
                });
            };

            var getParams = getUrlVar();
            if (getParams['new-id']) {
                $('#new-'+getParams['new-id']).trigger('click');
                getInfoNew(getParams['new-id']);
            }

            $(document).on('click', '.news-details', function(){
                var newNid = $(this).data('new-nid');
                getInfoNew(newNid);
            });
        })
    }

    Drupal.behaviors.realtyModalStockDetails= {
        attach: $(function () {
            var getInfoStock = function(id) {
                $.ajax({
                    url: '/realty_stock_details',
                    type: 'POST',
                    data: {
                        nid: id
                    },
                    success: function(response) {

                        if (response) {
                            $('.modal_stock').html(response);
                        }
                    },
                    error: function(response) {
                        alert('false');
                    }
                });
            };

            var getParams = getUrlVar();
            if (getParams['stock']) {
                console.log(getParams);
                $('#modal-stock-'+getParams['stock']).trigger('click');
                getInfoStock(getParams['stock']);
            }

            $(document).on('click', '.stock-details', function() {
                var stockNid = $(this).data('stock-nid');
                getInfoStock(stockNid);
            });
        })
    }

    Drupal.behaviors.realtyModalYoutubeVideo = {
        attach: $(function () {
            $(document).on('click', '.video-item', function() {
                var videoId = $(this).data('video-id');
                var iframe = '<iframe class="video-frame" src="https://www.youtube.com/embed/' + videoId + '?rel=0&amp;controls=0&amp;showinfo=0" frameborder="0" allowfullscreen=""></iframe>'
                $('#bs').html(iframe);
            })

            $(document).on('click', '.video-stop', function() {
                $('#bs').html('');
            })
        })
    }

    Drupal.behaviors.realtyInputDateFormat = {
        attach: $(function () {
            $("#date_issue").mask("99/99/9999");
        })
    }

    Drupal.behaviors.realtyProjectInfo = {
        attach: $(function () {

            $(window).scroll(function() {
                if ($(this).scrollTop() > 400) {
                    $('.pull').css({
                        'display': 'none'
                    });
                }
            });

            $('.nav_slide_button').click(function() {
                $('.pull').slideToggle();
            });

        })
    }

    Drupal.behaviors.realtyLoader = {
        attach: $(function () {

            $(document).on('click', '.pager-item', function() {
                console.log('rewrwe');
            });

        })
    }

    Drupal.behaviors.realtyFeedback = {
        attach: $(function () {

                $(".feedback-open").click(function() {
                    $(".feedback-menu").show();
                    $(this).hide();
                });
                $(".fb1_1").click(function() {
                    $('.feedback-open').trigger('click');
                    $('.fb1').trigger('click');
                });

                $(".fb1").click(function() {
                    $('.feedback-open').trigger('click');
                    $(".phone-order").show();
                    $(".guide-order").hide();
                    $(".question-order").hide();
                    $(".selection-order").hide();
                    $(".review-order").hide();
                    $(".close_feed_menu").hide();
                    $(".fb_i").css("background","#4c4c4c");
                    $(this).css("background","#3e90b1");
                });

                $("#fb2").click(function(){
                    $(".phone-order").hide();
                    $(".guide-order").show();
                    $(".question-order").hide();
                    $(".selection-order").hide();
                    $(".review-order").hide();
                    $(".close_feed_menu").hide();
                    $(".fb_i").css("background","#4c4c4c");
                    $(this).css("background","#3e90b1");
                });

                $("#fb3").click(function(){
                    $(".phone-order").hide();
                    $(".guide-order").hide();
                    $(".selection-order").hide();
                    $(".question-order").show();
                    $(".review-order").hide();
                    $(".close_feed_menu").hide();
                    $(".fb_i").css("background","#4c4c4c");
                    $(this).css("background","#3e90b1");
                });

                $("#fb4").click(function(){
                    $(".phone-order").hide();
                    $(".guide-order").hide();
                    $(".question-order").hide();
                    $(".selection-order").show();
                    $(".close_feed_menu").hide();
                    $(".fb_i").css("background","#4c4c4c");
                    $(this).css("background","#3e90b1");
                });

                $(".fb5").click(function(){
                    $(".selection-order").show();
                    $(".feedback-menu").show();
                    $(".feedback-open").hide();
                    $(".fb_i").css("background","#4c4c4c");
                    $(".fb4").css("background","#3e90b1");
                    $(".phone-order").hide();
                    $(".guide-order").hide();
                    $(".question-order").hide();
                });

                $(".close_feed").click(function(){
                    $(".fb-window").hide();
                    $(".close_feed_menu").show();
                });

                $(".close_feed_menu").click(function(){
                    $(".feedback-menu").hide();
                    $(".feedback-open").show();
                });

            }
        )}


    Drupal.behaviors.realtyAssessmenDeveloper = {
        attach : $(function () {

            var assessmenDeveloper = 0;

            // Инициализация звездочек
            if(Drupal.settings.developerRating) {
                $('#rating_dev').rating({
                    fx: 'full',
                    image: '/sites/all/themes/realty_theme/images/stars.png',
                    click: function(a1){
                        assessmenDeveloper = a1;
                    }
                });
            }

            $('#add-assessmen-developer').on('click', function () {

                // Если оценка выставлена
                if (assessmenDeveloper != 0) {

                    // Добавление информации в cookies о том что заявка уже была отправлена
                    var developer_tid =  $('#assessmenModal').data('developer-id');
                    var developer_assessmen = assessmenDeveloper;

                    var assessmens = [];
                    var developer_assessmens = $.cookie('developer_assessmens');

                    // Если в cookie есть информация об оценках застройщика
                    if(developer_assessmens) {
                        var assessmens = JSON.parse(developer_assessmens);
                    }

                    // Добавление tid зайстройщика в cookie
                    assessmens.push(developer_tid);

                    var assessmens_str = JSON.stringify(assessmens);
                    $.cookie('developer_assessmens', assessmens_str, {
                        expires: 365,
                        path: '/'
                    });

                    // Отправка запроса на добавление оценки застройщику
                    var colorDepth = screen.colorDepth?screen.colorDepth:screen.pixelDepth;
                    var size = screen.width + 'x' + screen.height + 'x' + colorDepth;

                    $.ajax({
                        url: '/add_assessmen_developer',
                        type: 'POST',
                        data: {
                            tid: developer_tid,
                            assessmen: developer_assessmen,
                            size: size
                        },
                        success: function(response) {

                        }
                    });
                }
                // Если оценка не выставлена
                else {

                }
            });
        })
    }

//end.
}(jQuery));

