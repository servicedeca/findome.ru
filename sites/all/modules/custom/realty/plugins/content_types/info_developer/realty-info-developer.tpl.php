<div class="container-fluid container-fix about-header" id="parallax" data-speed="3" data-type="background" style="background-image: url(<?php print $background;?>);">
  <div class="newcomplex-layer">
    <div class="container fin">

      <div class="col-xs-4 developer-contact">
        <h3>Телефон отдела продаж</h3>
        <a href="tel:+73833110505"><?php print $phone; ?></a>
        <h3>Веб сайт</h3>
        <a href="<?php print $website; ?>" target="_blank"><?php print $website; ?></a>
        <h3>Почтовый ящик</h3>
        <a href="mailto:op@12345.ru"><?php print $email; ?></a>
      </div>
      <div class="col-xs-8 developer-discription">
        <label>О застройщике</label>
        <div class="developer-discription-column">
          <p>
            <?php print $description; ?>
          </p>
        </div>
      </div>
    </div>
  </div>
</div>



<div class="new-complex-bg">

  <div class="about-c-line_3">
  </div>

  <div class="container fin" style="height:100%;">
    <div class="col-xs-12 zero-padding">
      <div class="row">
        <div class="col-xs-12 container-complex">
          <div class="progress-bar-flats">
            <div class="progress-bar-inner" style="width:<?php print $procent_app;?>%;">
            </div>
          </div>
          <div class="col-xs-6">
            <label>В продаже квартир</label>
            <p><?php print $apartments_active['all']?></p>
            <div class="col-xs-3 flat-count">
              <p><?php print $apartments_active['1']?></p>
              <h5>1кмн</h5>
            </div>
            <div class="col-xs-3 flat-count">
              <p><?php print $apartments_active['2']?></p>
              <h5>2кмн</h5>
            </div>
            <div class="col-xs-3 flat-count">
              <p><?php print $apartments_active['3']?></p>
              <h5>3кмн</h5>
            </div>
            <div class="col-xs-3 flat-count">
              <p><?php print $apartments_active['4_5']?></p>
              <h5>4+</h5>
            </div>

          </div>
          <div class="col-xs-6 text-right post">
            <label>Всего квартир</label>
            <p><?php print $apartments_all?></p>
          </div>
        </div>
      </div>
    </div>
  </div>

  <div class="about-c-line_3">
  </div>

  <div class="container fin" style="height:100%;">
    <div class="col-xs-12 zero-padding">
      <div class="col-xs-12 container-complex">
        <div class="col-xs-6">
          <img src="<?php print REALTY_FRONT_THEME_PATH?>/images/complex-question-dark.svg" class="meter-question"  rel="tooltip" data-placement="right" title="Средняя цена за кв.м. в продаже и изменение относительно первого числа текущего месяца.">
          <label>Средняя<br> цена за м<sup>2</sup></label>
          <p>
            <?php print $average_price; ?>
          </p>
          <div class="col-xs-2 flat-index">
            <?php print $img_x; ?>

            <p><?php print $x?>%</p>
          </div>
          <div class="col-xs-2 flat-value">
            <label>RUB</label>
          </div>

        </div>
        <div class="col-xs-6 text-right">
          <label>Стоимость<br> квартир</label>
          <p><span>от</span><?php print $min_cost?></p>
          <div class="col-xs-offset-6 col-xs-4 price-post">
            <p><span>до</span><?php print $max_cost?></p>
          </div>
          <div class="col-xs-2 flat-value">
            <label>RUB</label>
          </div>
        </div>
      </div>
    </div>
  </div>

  <div class="about-c-line_3">
  </div>

  <div class="container fin" style="height:100%;">
    <div class="col-xs-12 zero-padding">
      <div class="col-xs-12 container-complex">
        <div class="col-xs-6">
          <label>Количество введенных в эксплуатацию<br> жилых домов за последние 5 лет</label>
          <p><?php print $developer->field_developer_home_7y[LANGUAGE_NONE][0]['safe_value'];?></p>
        </div>
        <div class="col-xs-6 text-right">
          <label>Количество введенных в эксплуатацию<br> м<sup>2</sup>за последние 5 лет</label>
          <p><?php print $developer->field_developer_sqm_5y[LANGUAGE_NONE][0]['safe_value'];?></p>
        </div>
      </div>
    </div>
  </div>

  <div class="about-c-line_3">
  </div>

  <div class="container fin" style="height:100%;">
    <div class="col-xs-12 zero-padding">
      <div class="col-xs-12 container-complex">
        <div class="col-xs-6">
          <label>Количество текущих объектов / домов</label>
          <p><?php print $developer->field_developer_obj_home[LANGUAGE_NONE][0]['safe_value']; ?></p>
        </div>
        <div class="col-xs-6 text-right">
          <label>Отзывы на сайте</label>
          <p><?php print $good_finger . $review['positive'] . ' / '  . $review['negative'] . $bad_finger?></p>
        </div>
      </div>
    </div>
  </div>

</div>