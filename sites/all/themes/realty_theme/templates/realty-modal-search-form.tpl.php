<?php if($std == 'std'): ?>
  <div class="modal fade <?php print $modal_id;?>" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
    <div class="container container-modal-city zero-padding">
      <div class="col-xs-12 header-container-modal header-block">

        <div class="modal-text">
          <p><?php print $text; ?></p>
        </div>
        <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true" data-class="<?php print $checkbox_id?>">
          <?php print render($img_close)?>
        </button>
      </div>
      <div class="col-xs-12 list-modal-city <?php if ($checkbox_id == 'CheckboxMapComplex') print 'list-modal-city'; ?>">

        <?php foreach($options as $key => $option):?>
          <div class="col-xs-4 modal-list-item">
            <li>
              <div class="modal_checkbox">
                <span>

                  <label class="label-<?php print $modal_id;?>-<?php print $key?>" for="id-<?php print $modal_id;?>-<?php print $key?>">
                    <input type="checkbox" id="id-<?php print $modal_id;?>-<?php print $key?>" class="<?php print $class; ?> <?php print $checkbox_id?> <?php print $modal_id;?>-<?php print $key?>" value="<?php print $key. ';' .$option?>">
                    <?php print $option; ?>
                  </label>
                </span>
              </div>
            </li>
          </div>
        <?php endforeach ?>

      </div>
      <div class="col-xs-12 modal-button">
        <button type="button" class="ok-button <?php if ($submit) print 'search-button' ?> modal-but" data-dismiss="modal" aria-hidden="true">
          Применить
        </button>
      </div>
    </div>
  </div>
<?php endif;?>

<?php if($std == 'city'): ?>
  <div class="modal fade <?php print $modal_id;?>" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
    <div class="container container-modal-city zero-padding">
      <div class="col-xs-12 header-container-modal header-block">

        <div class="modal-text">
          <p><?php print $text; ?></p>
        </div>
        <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
          <?php print render($img_close)?>
        </button>
      </div>
      <div class="col-xs-12 list-modal-city">

        <?php foreach($options as $key => $option):?>
              <?php print $option; ?>
        <?php endforeach ?>

      </div>
      <div class="col-xs-12 modal-button">
        <button type="button" class="ok-button <?php if ($submit) print 'search-button' ?> modal-but" data-dismiss="modal" aria-hidden="true">
          Закрыть
        </button>
      </div>
    </div>
  </div>
<?php endif;?>

<?php if($std == 'sections'): ?>
  <div class="modal fade <?php print $modal_id;?>" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
    <div class="container container-modal-city zero-padding">
      <div class="col-xs-12 header-container-modal header-block">

        <div class="modal-text">
          <p><?php print $text; ?></p>
        </div>
        <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
          <?php print render($img_close)?>
        </button>
      </div>
      <div class="col-xs-12 list-modal-city <?php if ($checkbox_id == 'CheckboxMapComplex') print 'list-modal-city'; ?>">

        <?php foreach($options['homes'] as $id_home => $home): ?>
          <?php if(isset($options['sections_string'][$home])): ?>
            <div class="col-xs-12 modal-section-title">
              <p data-sections="<?php print $options['sections_string'][$home][0] ?>" id="home_id-<?php print $id_home ?>"><?php print $home; ?></p>
            </div>
          <?php endif; ?>
          <?php if(isset($options['sections'][$home])):?>
            <?php foreach($options['sections'][$home] as $id_section => $section): ?>
              <div class="col-xs-4 modal-list-item">
                <li>
                  <div class="modal_checkbox">
                    <span>
                      <input type="checkbox" id="id-<?php print $modal_id;?>-<?php print $id_section?>" class="<?php print $class; ?> <?php print $checkbox_id?> <?php print $modal_id;?>-<?php print $id_home?>" value="<?php print $id_section. ';' .$section; ?>">
                      <label class="label-<?php print $modal_id;?>-<?php print $id_section; ?>" for="id-<?php print $modal_id;?>-<?php print $id_section; ?>" id="label-<?php print $modal_id;?>-<?php print $id_section?>">Секция <?php print $section; ?></label>
                    </span>
                  </div>
                </li>
              </div>
            <?php endforeach; ?>
        <?php endif; ?>
        <?php endforeach; ?>

      </div>
      <div class="col-xs-12 modal-button">
        <button type="button" class="ok-button <?php if ($submit) print 'search-button' ?> modal-but" data-dismiss="modal" aria-hidden="true">
          Применить
        </button>
      </div>
    </div>
  </div>
<?php endif;?>

<?php if($std == 'type'): ?>
  <div class="modal fade <?php print $modal_id;?>" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
    <div class="container container-modal-city zero-padding">
      <div class="col-xs-12 header-container-modal header-block">
        <div class="modal-text">
          <p><?php print $text; ?></p>
        </div>
        <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true" data-class="<?php print $checkbox_id?>">
          <?php print render($img_close)?>
        </button>
      </div>

      <div class="col-xs-12 list-modal-city">

      <?php foreach($options as $key => $option):?>
        <div class="col-xs-6 modal-list-item">
          <li>
            <div class="modal_checkbox">
              <span>
                <input type="checkbox" id="id-<?php print $modal_id;?>-<?php print $key?>" class="<?php print $class; ?> <?php print $checkbox_id?> <?php print $modal_id;?>-<?php print $key?>" value="<?php print $key. ';' .$option?>">
                <label class="label-<?php print $modal_id;?>-<?php print $key?>" for="id-<?php print $modal_id;?>-<?php print $key?>"><?php print $option; ?></label>
              </span>
            </div>
          </li>
        </div>
      <?php endforeach; ?>

      </div>
      <div class="col-xs-12 modal-button">
        <button type="button" class="ok-button <?php if ($submit) print 'search-button' ?> modal-but" data-dismiss="modal" aria-hidden="true">Применить</button>
      </div>
    </div>
  </div>
<?php endif; ?>

<?php if($std == 'material' || $std == 'category'): ?>
  <div class="modal fade <?php print $modal_id;?>" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
    <div class="container container-modal-city zero-padding">
      <div class="col-xs-12 header-container-modal header-block">
        <div class="modal-text">
          <p><?php print $text; ?></p>
        </div>
        <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true" data-class="<?php print $checkbox_id?>">
          <?php print render($img_close)?>
        </button>
      </div>

      <div class="col-xs-12 list-modal-city">

        <?php foreach($options as $key => $option):?>
          <div class="col-xs-1 zero-padding mat-icon">
            <?php print $option['image']; ?>
          </div>

          <div class="col-xs-5 modal-list-item mat-fix mindic" data-id="dic<?php if ($checkbox_id == 'CheckboxMapCategory') print '-map'; ?>-<?php print $key ?>">
            <li>
              <div class="modal_checkbox">
									<span>
										<input type="checkbox" id="id-<?php print $modal_id; ?>-<?php print $key; ?>" class="<?php print $checkbox_id; ?> <?php print $modal_id;?>-<?php print $key; ?>" value="<?php print $key. ';' .$option['name']; ?>"/>
									  <label for="id-<?php print $modal_id;?>-<?php print $key; ?>"><?php print $option['name'] ?></label>
									</span>
              </div>
            </li>
          </div>
        <?php endforeach ?>


        <?php foreach($options as $key => $option):?>
          <div class="col-xs-12 mb mt-15" id="dic<?php if ($checkbox_id == 'CheckboxMapCategory') print '-map'; ?>-<?php print $key; ?>">
            <p>
              <?php print $option['description']; ?>
            </p>
          </div>
        <?php endforeach ?>

      </div>
      <div class="col-xs-12 modal-button">
        <button type="button" class="ok-button <?php if ($submit) print 'search-button' ?>" data-dismiss="modal" aria-hidden="true">Применить</button>
      </div>
    </div>
  </div>
<?php endif; ?>

<?php if($std == 'balcony'): ?>
  <div class="modal fade <?php print $modal_id;?>" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
    <div class="container container-modal-city zero-padding">
      <div class="col-xs-12 header-container-modal header-block">
        <div class="modal-text">
          <p><?php print $text; ?></p>
        </div>
        <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true" data-class="CheckboxBalconyLoggia">
          <?php print render($img_close)?>
        </button>
      </div>
      <div class="col-xs-12 list-modal-city">

        <div class="col-xs-4 modal-list-item">
          <li>
            <div class="modal_checkbox">
                <span>
                  <input type="checkbox" id="balcon" class="inlineCheckbox1 CheckboxBalconyLoggia CheckboxBalcony" value="<?php t('Балкон')?> ">
                  <label for="balcon"><?php print t('Балкон')?></label>
                </span>
            </div>
          </li>
        </div>

        <div class="col-xs-4 modal-list-item">
          <li>
            <div class="modal_checkbox">
                <span>
                  <input type="checkbox" id="id-loggia" class="inlineCheckbox1 CheckboxBalconyLoggia CheckboxLoggia" value="<?php t('Лоджия')?> ">
                  <label for="id-loggia"><?php print t('Лоджия')?></label>
                </span>
            </div>
          </li>
        </div>

        <div class="col-xs-4 modal-list-item">
          <li>
            <div class="modal_checkbox">
                <span>
                  <input type="checkbox" id="id-loggia-balcon" class="inlineCheckbox1 CheckboxBalconyLoggia CheckboxLoggia" value="<?php t('Балкон+Лоджия')?> ">
                  <label for="id-loggia-balcon"><?php print t('Балкон+Лоджия')?></label>
                </span>
            </div>
          </li>
        </div>

      </div>
      <div class="col-xs-12 modal-button">
        <button type="button" class="ok-button <?php if ($submit) print 'search-button' ?>" data-dismiss="modal" aria-hidden="true">Применить</button>
      </div>
    </div>
  </div>
<?php endif; ?>

<?php if ($std == 'slider'): ?>

  <div class="modal fade <?php print $modal_id; ?>" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
    <div class="container container-modal-city zero-padding">
      <div class="col-xs-12 header-container-modal header-block">
        <div class="modal-text">
          <p><?php print $text; ?></p>
        </div>
        <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
          <?php print render($img_close); ?>
        </button>
      </div>
      <div class="col-xs-4 col-xs-offset-2 modal-сounter">
        <p id="<?php print $modal_id; ?>-from_value">0.5<span>до</span></p>
        <label style="">от</label>
      </div>
      <div class="col-xs-4 left-modal-сounter">
        <p id="<?php print $modal_id; ?>-to_value">4+</p>
        <label><?php print $units; ?></label>
      </div>
      <div class="col-xs-10 col-xs-offset-1 zero-padding list-modal-city mslider">
        <div class="col-xs-12 zero-padding search-slider-modal">
          <input type="text" id="floorslider" name="example_name" value="" class="<?php print $class; ?> ion-slider"/>
        </div>
      </div>
      <div class="col-xs-12 modal-button">
        <button type="button" class="ok-button <?php if ($submit) print 'search-button'; ?>" data-dismiss="modal" aria-hidden="true">Применить</button>
      </div>
    </div>
  </div>

<?php endif; ?>

<?php if ($std == 'deadline'): ?>
  <div class="modal fade <?php print $modal_id; ?>" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
    <div class="container container-modal-city zero-padding">
      <div class="col-xs-12 header-container-modal header-block">
        <div class="modal-text">
          <p><?php print $text; ?></p>
        </div>
        <button type="button" class="close <?php if ($submit) print 'search-button' ?> close-modal" data-dismiss="modal" aria-hidden="true" data-class="<?php print $checkbox_id?>">
          <?php print render($img_close)?>
        </button>
      </div>

      <div class="col-xs-2 modal-date-q">
        <div class="col-xs-12">

        </div>
        <div class="col-xs-12">
          1 квартал
        </div>
        <div class="col-xs-12">
          2 квартал
        </div>
        <div class="col-xs-12">
          3 квартал
        </div>
        <div class="col-xs-12">
          4 квартал
        </div>
      </div>

      <div class="col-xs-10 list-modal-city list-modal-city-fix zero-padding">

        <?php foreach($options as $option): ?>
          <div class="col-xs-2 modal-date-e">
            <?php print '20'.$option; ?>
          </div>
        <?php endforeach; ?>

        <?php for ($i = 1; $i <= 4; $i++): ?>
          <?php for ($j = 0; $j < count($options); $j++): ?>
            <div class="col-xs-2 modal-list-item">
              <li>
                <div class="modal_checkbox">
                  <span>
                    <input type="checkbox" id="id-<?php print $modal_id; ?>-<?php print $options[$j].$i; ?>" class="<?php print $checkbox_id; ?> <?php print $modal_id;?>-<?php print $options[$j].$i; ?>"  value="<?php print $options[$j] . $i . ';' . $i. 'кв. ' . $options[$j]; ?>"/>
                  <label for="id-<?php print $modal_id; ?>-<?php print $options[$j].$i; ?>">&nbsp;</label>
                  </span>
                </div>
              </li>
              <?php if ($i != 4 && $j != count($options) - 1) print render($img_mp); ?>
            </div>
          <?php endfor; ?>
        <?php endfor; ?>

      </div>
      <div class="col-xs-12 modal-button">
        <button type="button" class="ok-button <?php if ($submit) print 'search-button' ?>" data-dismiss="modal" aria-hidden="true">Применить</button>
      </div>
    </div>
  </div>
<?php endif; ?>