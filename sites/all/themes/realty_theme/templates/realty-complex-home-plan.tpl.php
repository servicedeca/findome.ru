<div class="container-fluid container-fix plane-bg">
  <div class="about-header-layer-top">
  </div>
  <div class="container fin">
    <div id="complex-plan">
      <div class="col-xs-6 col-xs-offset-3 tab-menu zero-padding">
        <div class="col-xs-12 zero-padding">
          <div class="col-xs-4 <?php print $home_class;?>" id="<?php print $home_id;?>">
            <?php print t('Выберите дом, чтобы узнать о количестве и планировках квартир в продаже'); ?>
            <?php print $arrow_blue; ?>
          </div>
          <div class="col-xs-4 <?php print $section_class;?>" id="<?php print $section_id;?>">
            <a href="#" class="<?php print $section_a_class;?>" title="Выберите секцию">
              <?php print t('Секция'); ?>
              <?php print $arrow_gray; ?>
            </a>
          </div>
          <div class="col-xs-4 <?php print $apartment_class;?>" id="<?php print $apartment_id;?>">
            <a href="#" class="<?php print $apartment_a_class;?>" title="Выберите квартиру">
              <?php print t('Квартира');?>
            </a>
          </div>
        </div>
      </div>
      <?php if(isset($floor)):?>
        <ul class="col-xs-12 list-floor-link text-center">
          <span><?php print t('Этаж')?></span>
          <?php foreach($floors as $fl):?>
            <?php if($fl['number_section'] == $floor['number_section'] && $fl['home_tid'] == $floor['home_tid']):?>
              <?php if($fl['number_floor'] == $floor['number_floor']):?>
                <li class="number-floor-active">
              <?php endif;?>
              <?php if($fl['number_floor'] != $floor['number_floor']):?>
                <li>
              <?php endif;?>
              <?php print $fl['number_floor_link'];?>
              </li>
            <?php endif;?>
          <?php endforeach; ?>
        </ul>
      <?php endif;?>
      <div class="col-xs-12 right-part-complex zero-padding">
        <?php if($plan):?>
          <?php print $plan;?>
        <?php endif;?>
      </div>
    </div>
  </div>
</div>