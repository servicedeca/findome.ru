<div id="hellopreloader_preload">
</div>

<?php if (isset($how_it_works)): ?>

<div class="container-fluid container-fix" >
  <div class="col-xs-12 big-height plusplus how-block pull">
<!--    <div class="col-xs-12 topline-howblock">
      <div class="col-xs-4">
        <?php /*print $img_hbi1; */?></php>
        <h2>Поиск<br>квартир</h2>
        <p>Удобная форма поиска и сравнения квартир по множеству параметров поможет Вам выбрать квартиру от застройщика из тысячи актуальных вариантов в новостройках.<br> Не хотите искать самостоятельно?<br>Специалисты Findome совершенно бесплатно подберут вам квартиру в новостройке.</p>
        <a href="#">Подробнее</a>
      </div>
      <div class="col-xs-4">
        <?php /*print $img_hbi3; */?></php>
        <h2>Отправка<br>заявки</h2>
        <p>Отправьте заявку напрямую застройщику или специалисту Findome для получения консультации по новостройке или на подбор квартиры от застройщика. Специалисты оперативно свяжутся с Вами по указанному в заявке телефону.</p>
        <a href="#">Подробнее</a>
      </div>
      <div class="col-xs-4">
        <?php /*print $img_hbi4; */?></php>
        <h2>Юридическое сопровождение <br> сделки</h2>
        <p>При необходимости специалисты Findome совершенно бесплатно окажут юридическое сопровождение сделки оформления ДДУ с застройщиком.</
        <a href="#">Подробнее</a>
      </div>
    </div>-->
  </div>
</div>

<?php endif; ?>

<div class="col-xs-12 menu-parent zero-padding">
  <div id="menu">
    <div class="big-head-line l50 idi">
    </div>
    <ul>
      <li class="main-logo">
        <?php if(!empty($logo)):?>
          <?php print render($logo); ?>
        <?php endif?>
      </li>
      <li class="page-scroll">
        <a data-toggle="modal" data-target=".modal_cities">
          <?php if (isset($city)):?>
            <?php print $city ?>
          <?php endif; ?>
        </a>
      </li>
      <?php if(!empty($main_menu)):?>
        <?php foreach($main_menu as $item):?>
          <li><?php print $item?></li>
        <?php endforeach ?>
      <?php endif;?>
      <li>
        <?php if(isset($logout_register)):?>
          <?php print $logout_register . '/'; ?>
        <?php endif;?>
        <?php print $login_profile; ?>
      </li>
    </ul>
  </div>
</div>

<div id="wrapper">
  <div id="content">
    <?php print render($title_prefix); ?>
    <?php print render($title_suffix); ?>
    <?php if (!empty($action_links)): ?>
      <ul class="action-links">
        <?php print render($action_links); ?>
      </ul>
    <?php endif; ?>
    <?php print render($page['content']); ?>
  </div>
</div>

<div class="container-fluid container-fix" id="footer">
  <div class="container fin">
    <div class="col-xs-3 footer-topline">
      <?php print $footer_logo; ?>
    </div>
    <div class="col-xs-9 footer-topline">
      <p>
        <span></span>
        <br>
        Findome - поисковик квартир в новостройках. Сервис поможет вам самостоятельно подобрать и купить квартиру в новостройке. На одной площадке собрана вся правда о новостройках от застройщиков Новосибирска: динамика строительства, динамика продаж и изменения цен, независимый рейтинг застройщиков и жилых комплексов. В базу Findome попадают только проверенные и надежные застройщики. Сервис является абсолютно бесплатным для пользователей: Findome не взимает комиссий и не устанавливает наценок - все квартиры в базе напрямую от застройщиков. С помощью Findome вы выбираете новостройку и бронируете квартиру напрямую у застройщика. Findome.ru – лучший способ купить новостройку от застройщика.»
      </p>
    </div>
    <div class="row">
      <div class="col-xs-4 footer-item-list">
        <h2>Findome</h2>
        <ul>
          <li>
            <a href="/about">О проекте</a>
          </li>
          <li>
            <a href="/guide">Путеводитель
            </a>
          </li>
          <li>
            <a href="/faq">FAQ</a>
          </li>
          <li>
            <a href="/contacts">Контакты</a>
          </li>
        </ul>
      </div>
      <div class="col-xs-6 footer-item-list">
        <h2>Важно</h2>
        <ul>

          <?php foreach ($footer_links['policy'] as $key => $title): ?>
            <li>
              <a href="/policy?p=<?php print $key; ?>"><?php print $title; ?></a>
            </li>
          <?php endforeach; ?>

        </ul>
      </div>
      <div class="col-xs-2 footer-item-list">
        <h2>Полезно</h2>

        <?php foreach ($footer_links['cooperation'] as $key => $title): ?>
          <li>
            <a href="/cooperation?p=<?php print $key; ?>"><?php print $title; ?></a>
          </li>
        <?php endforeach; ?>

        </ul>
      </div>
    </div>
    <div class="row" style="margin-top:35px; margin-bottom:35px;">
      <div class="col-xs-4  footer-list-social">
        <h2>Мы в сети</h2>
        <ul>

          <li>
            <?php print $link_facebook; ?>
          </li>
          <li>
            <?php print $link_instagram; ?>
          </li>
          <li>
            <?php print $link_vk; ?>
          </li>
          <li>
            <?php print $link_twitter; ?>
          </li>
          <li>
            <?php print $link_google; ?>
          </li>

        </ul>
      </div>
      <div class="col-xs-6 footer-contact-list">
        <h2>Контакты</h2>
        <p><?php print $link_phone; ?></p>
        <p><?php print $link_mail; ?></p>
      </div>
    </div>
  </div>
</div>

<?php print $modals;?>