<div class="container-fluid container-fix">
  <div class="row">
    <div class="col-xs-3 big-height fiftyminus zero-padding bbl">

      <div class="col-xs-12 zero-padding half-item">
        <a href="<?php print $all_complexes ?>">
          <div class="col-xs-12 index-item zero-padding">
            <h2>
              <span>
               <!-- --><?php /*print t('Residential')*/?>
              </span><?php print t('Новостройки')?>
            </h2>
            <p>
              <?php print t('Перейти к списку всех новостроек');?>
            </p>
          </div>
        </a>
      </div>

      <div class="col-xs-12 zero-padding half-item cork">
        <?php print $image_complexes; ?>
      </div>

    </div>

    <div class="col-xs-9 big-height parent">
      <div class="big-height">
        <div class="col-xs-4 beige-block zero-padding">
          <div id="prev" class="arr-prev next-complex" data-tid-city='<?php print $city_tid;?>' data-nid-complex='<?php print $prev;?>'>
            <?php print $img_right; ?>
          </div>
          <div id="next" class="arr-next next-complex" data-nid-complex='<?php print $next;?>'>
            <?php print $img_left; ?>
          </div>
          <div id="realty-logo-complex" class="col-xs-12 half-item zero-padding">
            <?php if (isset($complex['logo'])):?>
              <?php print $complex['logo']?>
            <?php endif?>
          </div>
          <div class="col-xs-12 second-quarter-item zero-padding display-table  slider-info">
            <div class="vertical">
              <h2 id="realty-title-complex">
                <?php print $complex['title']?>
              </h2>
            </div>
          </div>
          <div class="col-xs-12 third-quarter-item zero-padding item-text-field">
            <div class="row" style="height:33%;">
              <div class="col-xs-6 slider-complex-infoitem">
                <label>этажность</label>
                <p id="realty-floor-complex">
                  <?php print $complex['floor']; ?>
                </p>
              </div>
              <div class="col-xs-6 slider-complex-infoitem sci-right">
                <label>застройщик</label>
                <h5 id="realty-developer-complex">
                  <?php print $complex['developer']?>
                </h5>
              </div>
            </div>
            <div class="row" style="height:33%;">
              <div class="col-xs-6 slider-complex-infoitem">
                <label>квартир в продаже</label>
                <p id="realty-apartment-complex">
                  <?php print $complex['apartments']?>
                </p>
              </div>
              <div class="col-xs-6 slider-complex-infoitem sci-right">
                <label>средняя цена за м<sup>2</sup></label>
                <?php if($complex['avg_price']):?>
                  <p id="realty-price-complex">
                    <?php print $complex['avg_price']; ?>
                  </p>
                <?php endif?>
              </div>
            </div>
            <div class="row" style="height:34%;">
              <div class="col-xs-6 slider-complex-button">
                <div id="realty-plan-complex" class="vertical">
                  <?php print $complex['plan']?>
                </div>
              </div>
              <div class="col-xs-6 slider-complex-button slider-complex-button-right">
                <div id="realty-details-complex" class="vertical">
                  <?php print $complex['details']?>
                </div>
              </div>
            </div>
          </div>
        </div>
        <div id="realty-image-complex" class="col-xs-8 big-height zero-padding">
          <?php print render($complex['image'])?>
        </div>
        <div style="display: none" id="realty-image-complex-hide" class="col-xs-8 big-height zero-padding">
        </div>
      </div>
    </div>

  </div>
</div>

