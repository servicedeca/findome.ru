<div class="container-fluid container-fix about-header about-header-bigger" id="parallax" data-speed="3" data-type="background" style="background-image: url(<?php print $background;?>);">
  <div class="about-header-layer">
    <div class="container fin apartment-body">

      <div class="col-xs-8 ap-plane">
        <?php print $apartment_plan;?>
      </div>
      <div class="col-xs-4 zero-padding apartment-tab-header">
        <div class="col-xs-12 about-inner-item">
          <lebel>Общая площадь, м<sup>2</sup></lebel>
          <h1><?php print $content['field_gross_area']['#items'][0]['value']; ?></h1>
        </div>
        <div class="col-xs-12 about-inner-item">
          <lebel>Стоимость, руб.</lebel>
          <h3><?php print number_format($full_cost, 0, '', ' ' );?></h3>
        </div>
        <div class="col-xs-12 about-inner-item">
          <lebel>Тип</lebel>
          <h2><?php print $content['field_number_rooms'][0]['#markup']?></h2>
        </div>
        <div class="col-xs-12 about-inner-item">
          <lebel>Жилой комплекс</lebel>
          <h2>
            <?php print $complex;?>
          </h2>
        </div>
        <div class="col-xs-12 about-inner-item">
          <lebel>Адрес</lebel>
          <h2>
            <?php print $address;?>
          </h2>
        </div>
        <div class="col-xs-12 about-inner-item">
          <lebel>Секция</lebel>
          <h2><?php print $field_section[0]['value']; ?></h2>
        </div>
        <div class="col-xs-12 about-inner-item">
          <lebel>Балкон</lebel>
          <h2>
            <?php if ($field_balcony[0]['value']) : ?>
              <?php print "Балкон" ?>
            <?php elseif ($field_loggia[0]['value']) : ?>
              <?php print "Лоджия" ?>
            <?php elseif ($apartment['balcony_loggia'][0]['value']) :?>
              <?php print 'Балкон и лоджия'?>
            <?php else: ?>
              <?php print "Нет" ?>
            <?php endif; ?>
          </h2>
        </div>
        <div class="col-xs-12 about-inner-item">
          <lebel>Этаж</lebel>
          <h2><?php print $field_apartment_floor[0]['value']; ?></h2>
        </div>
        <div class="col-xs-12 about-inner-item">
          <lebel>Цена руб. за м<sup>2</sup></lebel>
          <h2><?php print number_format($content['field_price']['#items'][0]['value'], 0, '', ' ' );?></h2>
        </div>
        <div class="col-xs-12 about-inner-item">
          <lebel>Срок сдачи</lebel>
          <h2><?php print $deadline; ?></h2>
        </div>
        <div class="col-xs-12 about-inner-item">
          <lebel>Жилая площадь, м<sup>2</sup></lebel>
          <h2>
            <?php if($content['field_living_space']['#items'][0]['value']): ?>
              <?php print $content['field_living_space']['#items'][0]['value']; ?>
            <?php else: ?>
              <?php print '-'; ?>
            <?php endif; ?>
          </h2>
        </div>
        <div class="col-xs-12 about-inner-item">
          <lebel>
            <?php print t('застройщик')?>
          </lebel>
          <h2>
            <?php print $developer?>
          </h2>
        </div>
        <div class="col-xs-12 about-inner-item">
          <lebel>Высота потолков, м</lebel>
          <h2><?php print $cieling_height; ?></h2>
        </div>
        <div class="col-xs-12 about-inner-item">
          <lebel>Материал стен</lebel>
          <h2><?php print $material; ?></h2>
        </div>
      </div>
      <div class="col-xs-8 flat-legend">
        <?php print $img_flat_legend; ?>
      </div>
    </div>
  </div>
</div>

<?php print $modal;?>

<!-- Modal mortgage apartment -->
<div class="modal fade modal_mortgage" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <div class="container container-mortgage-booking zero-padding" id="mortgage_apartment">

  </div>
</div>