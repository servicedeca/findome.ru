<?php// print $feedback_block; ?>

<form action="/search/1" method="post" style="display: none"> <button id="hidden-but-search"></button></form>


<div class="notification-body">
  <div class="container fin">
    <p id="apt-info"></p>
    <label id="apt-comp-count"></label>
    <a href="/comparison">Сравнить</a>
    <?php print $notify_close; ?>
  </div>
</div>

<?php arg(0) != 'search' ? print $a = theme('realty_feedback_block') : 0; ?>


<!--<div id="hellopreloader_preload">-->
<!--</div>-->
<div class="realty-preload">
</div>
<?php if (isset($how_it_works)): ?>

  <div class="container-fluid container-fix" >
    <div class="">

      <!--<div class="col-xs-12 topline-howblock">
        <div class="col-xs-4">
          <?php /*print $img_hbi1; */?>
          <h2>Поиск <br>квартир</h2>
          <p>Удобная форма поиска и сравнения квартир по множеству параметров поможет Вам выбрать квартиру от застройщика из тысячи актуальных вариантов в новостройках.</p>
        </div>
        <div class="col-xs-4">
          <?php /*print $img_hbi2; */?>
          <h2>Отправка <br>заявки</h2>
          <p>Отправьте заявку напрямую застройщику или специалисту Findome для получения консультации по новостройке или на подбор квартиры от застройщика. Специалисты оперативно свяжутся с Вами по указанному в заявке телефону.</p>
        </div>
        <div class="col-xs-4">
          <?php /*print $img_hbi3; */?>
          <h2>Заключение<br>договора</h2>
          <p>Специалист отдела продаж застройщика проинструктирует Вас о порядке заключения договора и назначит время встречи. Процесс покупки осуществляется в отделе продаж компании-застройщика.</p>
        </div>
      </div>-->

    </div>
  </div>

<?php endif; ?>

<div class="menu-parent zero-padding">

  <div id="menu" class="<?php print $class; ?>">
    <div class="big-head-line l50 idi">
    </div>
    <ul class="col-xs-12 zero-padding">
      <li class="main-logo">
        <?php if(!empty($logo)):?>
          <?php print render($logo); ?>
        <?php endif; ?>
      </li>

      <?php if (isset($link_search)): ?>
        <li class="hidden-index">
          <?php print $link_search; ?>
        </li>
      <?php endif; ?>

      <?php if (isset($link_complexes)): ?>
        <li class="hidden-index">
          <?php print $link_complexes; ?>
        </li>
      <?php endif; ?>

      <?php if (isset($link_developers)): ?>
        <li class="hidden-index">
          <?php print $link_developers; ?>
        </li>
      <?php endif; ?>

      <?php if (isset($link_mortgage)): ?>
        <li class="hidden-index hidden-mort">
          <?php print $link_mortgage; ?>
        </li>
      <?php endif; ?>


        <div class="phone-top">

            <svg version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" width="24.89px"
                 height="22.625px" viewBox="0 0 24.89 22.625" enable-background="new 0 0 24.89 22.625" xml:space="preserve">
            <path fill="#4c4c4c" d="M21.416,3.336c0,0-2.408-3.867-5.909-1.682C12.006,3.84,9.312,6.437,8.276,8.653
            C7.239,10.869,4.49,16.61,7.001,19.724c0,0,1.369,1.454,2.953,2.224l0.745-6.05c0,0-1.502-0.751-0.938-2.129
            c0.564-1.378,3.886-6.635,3.886-6.635s1.138-1.587,2.691-0.52L21.416,3.336z"/>
                <path fill="#4c4c4c" d="M21.691,3.792c0,0,0.286,0.242,0.315,0.984c0.03,0.743-0.226,0.897-0.226,0.897l-3.501,2.186
            c0,0-0.297-0.028-0.623-0.107c-0.327-0.079-1.032-0.551-0.889-0.776C16.911,6.751,21.691,3.792,21.691,3.792z"/>
                <path fill="#4c4c4c" d="M11.283,16.011l1.277,0.768c0,0,0.204,0.222,0.193,0.782c-0.012,0.56-0.415,3.708-0.415,3.708
            s-0.093,0.54-0.512,0.655c-0.419,0.116-1.34,0.326-1.34,0.326L11.283,16.011z"/>
            </svg>
            <span><a href="tel:+73833541433">+7 (383) 354 14 33</ a></span>
        </div>

      <ul class="header-icons">

        <?php if ($_GET['q'] == "<front>"): ?>
          <li><a href="/about" rel="tooltip" data-placement="bottom" title="" data-original-title="О проекте">
              <svg version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px"
                   y="0px" width="25px" height="25px" viewBox="0 0 12 13" enable-background="new 0 0 12 13"
                   xml:space="preserve">
                  <path class="hi" fill="#D3D3D3" d="M9.676,3.587H5.265v2.395h3.676v2.417H5.265v3.44H2.324V1.16h7.352V3.587z"></path>
              </svg>
            </a></li>
          <li>
            <a data-toggle="modal" data-target=".modal_cities" rel="tooltip" data-placement="bottom" title="Выбор города">
              <?php print $img_choose_city; ?>
            </a>
          </li>
        <?php else: ?>
          <li>
            <a href="/comparison"  rel="tooltip" data-placement="bottom" id="comprasion_button" title="Квартир в сравнении (0)">
              <?php print $img_comparison; ?>
            </a>
          </li>

          <li>

          <li>
            <a data-toggle="modal" data-target=".modal_cities" rel="tooltip" data-placement="bottom" title="Выбор города">
              <?php print $img_choose_city; ?>
            </a>
          </li>

          <?php if(!empty($main_menu)):?>
            <?php foreach($main_menu as $item):?>
              <li><?php print $item?></li>
            <?php endforeach ?>
          <?php endif;?>

          <li><?php print $login_profile; ?></li>
          <?php if(isset($logout_register)):?>
            <li><?php print $logout_register; ?></li>
          <?php endif;?>
        <?php endif; ?>

      </ul>

    </ul>
  </div>

</div>

<?php print $modals;?>

<!-- Yandex.Metrika counter --><script type="text/javascript"> (function (d, w, c) { (w[c] = w[c] || []).push(function() { try { w.yaCounter32625050 = new Ya.Metrika({ id:32625050, clickmap:true, trackLinks:true, accurateTrackBounce:true, webvisor:true }); } catch(e) { } }); var n = d.getElementsByTagName("script")[0], s = d.createElement("script"), f = function () { n.parentNode.insertBefore(s, n); }; s.type = "text/javascript"; s.async = true; s.src = "https://mc.yandex.ru/metrika/watch.js"; if (w.opera == "[object Opera]") { d.addEventListener("DOMContentLoaded", f, false); } else { f(); } })(document, window, "yandex_metrika_callbacks");</script><noscript><div><img src="https://mc.yandex.ru/watch/32625050" style="position:absolute; left:-9999px;" alt="" /></div></noscript><!-- /Yandex.Metrika counter -->

<!--Google Analitics-->
<script>
  (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
      (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
    m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
  })(window,document,'script','//www.google-analytics.com/analytics.js','ga');

  ga('create', 'UA-71432128-1', 'auto');
  ga('send', 'pageview');

</script>

<script>
    (function(){
        var partner_server = 'http://affiliate.findome.ru';
        var program = '362050dd-5c05-4ad1-8f90-8acae3159708';
        var partnerId = undefined;
        var path =  window.location.search.substring(1);
        var arr = path.split('&');
        for(var i = 0; i<arr.length; i++){
            var key = arr[i];
            if(!key) continue;
            // startWith es5
            if(key.lastIndexOf('partner', 0) === 0){
                var arr2 = key.split('=');
                if(arr2[0] === 'partner'){
                    partnerId = arr2[1];
                }
            }
        }
        if(partnerId){
            function htmlToElement(html) {
                var template = document.createElement('template');
                template.innerHTML = html;
                return template.content.firstChild;
            }
            var url = partner_server+'/customer/click/'+program+'/'+partnerId;
            var s = htmlToElement('<img style="display: none;" src="'+url+'">');
            document.body.appendChild(s);
        }
    }());
</script>