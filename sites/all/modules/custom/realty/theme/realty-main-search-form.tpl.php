<div class="col-xs-12 zero-padding search-top">
  <div class="col-xs-4 zero-padding search-item">

    <div class="col-xs-12 zero-padding search-title" style="width: 99.7%;">
      <div class="vertical">
        <h2>Поиск<span>по параметрам</span>
        </h2>
      </div>
    </div>

    <div data-toggle="modal" data-target=".modal_developer" class="col-xs-12 zero-padding search-cell">
      <?php print $img_plus; ?>
      <input class="search-main-input-developer" value="<?php print $default_value; ?>" readonly>
      <label><?php print t('Застройщик'); ?></label>
    </div>

    <div data-toggle="modal" data-target=".modal_area" class="col-xs-12 zero-padding search-cell">
      <?php print $img_plus; ?>
      <input class="search-main-input-area" value="<?php print $default_value; ?>" readonly>
      <label><?php print t('Area')?></label>
    </div>
    <div data-toggle="modal" data-target=".modal_deadline" class="col-xs-12 zero-padding search-cell">
      <?php print $img_plus; ?>
      <input class="search-main-input-deadline" value="<?php print $default_value; ?>" readonly>
      <label>Срок сдачи</label>
    </div>

  </div>

  <div class="col-xs-4 zero-padding search-item">
    <a data-toggle="modal" data-target=".modal_cities" class="col-xs-8 zero-padding search-title">
      <div class="vertical">
        <p id="city_id" data-city-id="<?php print $city_id; ?>"><?php print $city;?></p>
        <span class="search-city-span">выбрать другой город</span>
      </div>
    </a>

    <a class="col-xs-4 zero-padding search-title index-clean-filters" id="realty-main-filter-reset">
      <div class="vertical">
        <p>Очистить <br>фильтры</p>
        <?php print $img_cross; ?>
      </div>
    </a>

    <div data-toggle="modal" data-target=".modal_complex" class="col-xs-12 zero-padding search-cell">
      <?php print $img_plus; ?>
      <input class="search-main-input-complex" value="<?php print $default_value; ?>" readonly>
      <label><?php print t('Жилые комплексы'); ?></label>
    </div>

    <div data-toggle="modal" data-target=".modal_type" class="col-xs-12 zero-padding search-cell">
      <?php print $img_plus; ?>
      <input class="search-main-input-type" value="<?php print $default_value; ?>" readonly>
      <label><?php print t('Количество комнат'); ?></label>
    </div>

    <div data-toggle="modal" data-target=".modal_category" class="col-xs-12 zero-padding search-cell">
      <?php print $img_plus; ?>
      <input class="search-main-input-category" value="<?php print $default_value; ?>" readonly>
      <label>Категория</label>
    </div>

  </div>

  <a id="left-item" class="col-xs-4 zero-padding search-item seach-button search-button-fix">
    <?php print render($form['submit'])?>
    <div class="index-item ii-fix iab" id="left-left-item">
      <h3>Показать <br><span for="left-item" id="count_result"><?php print $count_result; ?></span><br> квартир(ы)</h3>
      <p>перейти к выдаче результатов</p>
    </div>
  </a>


</div>

 <!-- bottom -->

<div class="col-xs-12 zero-padding search-bottom">
  <div class="col-xs-4 zero-padding search-item">
    <div data-toggle="modal" data-target=".modal_floor" class="col-xs-12 zero-padding search-cell">
      <?php print $img_plus; ?>
      <input class="search-main-input-floor" value="<?php print $default_value; ?>" readonly>
      <label><?php print t('Этаж'); ?></label>
    </div>


    <div data-toggle="modal" data-target=".modal_material" class="col-xs-12 zero-padding search-cell">
      <?php print $img_plus; ?>
      <input class="search-main-input-masonry" value="<?php print $default_value; ?>" readonly>
      <label><?php print t('Материал стен'); ?></label>
    </div>


    <div data-toggle="modal" data-target=".modal_metro" class="col-xs-12 zero-padding search-cell">
      <?php print $img_plus; ?>
      <input class="search-main-input-metro" value="<?php print $default_value; ?>" readonly>
      <label><?php print t('Метро'); ?></label>
    </div>

    <div data-toggle="modal" data-target=".modal_balkon" class="col-xs-12 zero-padding search-cell">
      <?php print $img_plus; ?>
      <input class="search-main-input-balcony" value="<?php print $default_value; ?>" readonly>
      <label><?php print t('Балкон'); ?></label>
    </div>

  </div>

  <div class="col-xs-8 zero-padding search-slider-body" id="islider">

    <div class="col-xs-12 zero-padding seach-slider-line" style="height:0.5%">
    </div>

    <div class="col-xs-12 zero-padding seach-slider-line">
      <div class="zero-padding seach-slider-description">
        <h3>ЦЕНА</h3>
        <p id="current-price">от <span>35</span> до <span>100</span> тыс.р. за м<sup>2</sup></p>
      </div>
      <div class="zero-padding search-slider">
        <input type="text" id="meter-price" name="example_name" value="" class="price ion-slider"/>
      </div>
    </div>

    <div class="col-xs-12 zero-padding seach-slider-line">
      <div class="zero-padding seach-slider-description">
        <h3>ПЛОЩАДЬ</h3>
        <p id="current-sq">от <span>15</span> до <span>95 </span>м<sup>2</sup></p>
      </div>
      <div class="zero-padding search-slider">
        <input type="text" id="meters" name="example_name" value="" class="sq ion-slider count-result"/>
      </div>
    </div>

    <div class="col-xs-12 zero-padding seach-slider-line mt--1">
      <div class="zero-padding seach-slider-description">
        <h3>СТОИМОСТЬ</h3>
        <p id="current-coast">от <span>0.9</span> до <span>4.5</span> млн.р.</p>
      </div>
      <div class="zero-padding search-slider">
        <input type="text" id="flat-price" name="example_name" value="" class="coast ion-slider"/>
      </div>
    </div>

    <div class="col-xs-12 zero-padding seach-slider-line" style="height:2.5%">
    </div>
  </div>
</div>

<!-- other -->


<div id="zk"></div>
<div id="form-search-hidden" style="margin-top: 200px">
  <?php print drupal_render_children($form); ?>
</div>