<div class="new-complex-bg">
  <div class="col-xs-12 zero-padding new-complex-line">
  </div>
  <div class="container fin" style="height:100%;">
    <ul class="col-xs-12 zero-padding complex-undermenu" role="tablist">
      <li role="presentation" class="active">
        <a href="#text1"  role="tab" data-toggle="tab" aria-controls="home" aria-expanded="true">
          Общая информация
        </a>
      </li>
<!--      <li role="presentation">
        <a href="#text2" role="tab" data-toggle="tab" aria-controls="home" aria-expanded="false">
          Инфраструктура
        </a>
      </li>-->
      <li role="presentation">
        <a href="#text3" role="tab" data-toggle="tab" aria-controls="profile" aria-expanded="false">
          Документы
        </a>
      </li>
    </ul>
  </div>

  <div class="tab-content">

    <div role="tabpanel" class="tab-pane fade active in modal-info-text" aria-labelledby="home-tab" id="text1">
      <div class="about-c-line_1">
      </div>
      <div class="about-c-line_2">
      </div>

      <div class="container-fluid container-fix about-header" data-speed="3" data-type="background" style="background-image: url(<?php print $background; ?>);">
        <div class="newcomplex-layer">
          <div class="container fin">
            <div class="cir"><?php print $readiness; ?>%</div>
            <div class="row">
              <div class="col-xs-6 zero-padding complex-image">
                <?php print $img; ?>
              </div>
              <div class="col-xs-6 complex-discription">
                <label>О комплексе</label>
                <p>
                  <?php if(isset($mini_description)):?>
                    <?php print $mini_description;?>
                  <?php endif?>
                </p>
                <label>Застройщик</label>
                <h2><?php print $developer; ?></h2>
              </div>
            </div>
          </div>
        </div>
      </div>

      <div class="container fin" style="height:100%;">
        <div class="col-xs-12 zero-padding">
          <div class="row">
            <div class="col-xs-12 container-complex">
              <div class="progress-bar-flats">
                <div class="progress-bar-inner" style="width:<?php print $procent; ?>%;">
                </div>
              </div>
              <div class="col-xs-6">
                <label>В продаже квартир</label>
                <p><?php print $count_active_apartments; ?></p>
                <div class="col-xs-3 flat-count">
                  <p><?php print $count_1; ?></p>
                  <h5>1кмн</h5>
                </div>
                <div class="col-xs-3 flat-count">
                  <p><?php print $count_2; ?></p>
                  <h5>2кмн</h5>
                </div>
                <div class="col-xs-3 flat-count">
                  <p><?php print $count_3; ?></p>
                  <h5>3кмн</h5>
                </div>
                <div class="col-xs-3 flat-count">
                  <p><?php print $count_other; ?></p>
                  <h5>4+</h5>
                </div>

              </div>
              <div class="col-xs-6 text-right post">
                <label>Всего квартир</label>
                <p><?php print $count_apartments; ?></p>
              </div>
            </div>


            <div class="col-xs-12 container-complex">
              <div class="col-xs-6">
                <?php print $img_cost; ?>
                <label>Средняя<br> цена за м<sup>2</sup></label>
                <p><?php print $price_from; ?></p>
                <div class="col-xs-2 flat-index">
                  <?php print $img_x; ?>
                  <p><?php print $x; ?>%</p>
                </div>
                <div class="col-xs-2 flat-value">
                  <label>RUB</label>
                </div>

              </div>
              <div class="col-xs-6 text-right">
                <label>Стоимость<br> квартир</label>
                <p><span>от</span><?php print number_format($cost[0]->cost_min, 0, ',', ' ' ); ?></p>
                <div class="col-xs-offset-6 col-xs-4 price-post">
                  <p><span>до</span><?php print number_format($cost[0]->cost_max, 0, ',', ' ' ); ?></p>
                </div>
                <div class="col-xs-2 flat-value">
                  <label>RUB</label>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>

      <div class="about-c-line_3">
      </div>

      <div class="container fin" style="height:100%;">
        <div class="col-xs-12 zero-padding">
          <div class="row">

            <div class="col-xs-12 container-complex">
              <div class="col-xs-6">
                <label>Срок сдачи</label>
                <p style="font-size:40px;"><?php print $field_queue_quarter; ?> квартал <?php print $field_queue_year; ?></p>
                <div class="col-xs-12 flat-start">
                  <p>Начало строительства<span><?php print $start_building; ?></span></p>
                </div>
              </div>
              <div class="col-xs-6 text-right">
                <label>этажность</label>
                <p><?php print $complex_floor; ?></p>
              </div>
            </div>

            <div class="col-xs-12 container-complex">
              <div class="col-xs-8">
                <label>Метериал стен</label>
                <p style="font-size:35px;     margin-top: 0px;"><?php print $material; ?></p>
              </div>
              <div class="col-xs-4 text-right flat-top">
                <label>высота потолков</label>
                <p><?php print $ceiling_height; ?><span> м</span></p>
              </div>
            </div>

            <div class="col-xs-12 container-complex">
              <div class="col-xs-6">
                <label>Финансирование</label>
                <?php print $img_finance; ?>
                <p style="font-size:35px;     margin-top: 0px;"><?php print $financing; ?></p>
              </div>
              <div class="col-xs-6 text-right">
                <label>тип договора</label>
                <?php print $img_contract; ?>
                <p style="font-size:35px;     margin-top: 0px;"><?php print $contract; ?></p>
              </div>
            </div>
          </div>
        </div>
      </div>

      <div class="about-c-line_4">
      </div>

      <div class="container fin">
        <div class="col-xs-12">
          <div class="complex-check-item">
            <p>видео<br>наблюдение</p>
            <?php print $img_videovision; ?>
          </div>
          <div class="complex-check-item">
            <p>подземная<br>парковка</p>
            <?php print $img_parking; ?>
          </div>
          <div class="complex-check-item">
            <p>отгороженность<br>территории</p>
            <?php print $img_fenced; ?>
          </div>
          <div class="complex-check-item">
            <p><br>охрана</p>
            <?php print $img_security; ?>
          </div>
          <div class="complex-check-item">
            <p>чистовая<br>отделка</p>
            <?php print $img_fine_finishing; ?>
          </div>
          <h3 class="JK-title"><br><br>План ЖК</h3>
        </div>
      </div>

      <div class="about-c-line_5">
      </div>
      <div class="about-c-line_6">
      </div>

      <div class="container-fluid complex-map">
        <?php print $map; ?>
      </div>

      <?php /*print $plan_complex; */?>

      <!-- План ЖК -->

      <div class="container fin">

        <div id="complex-plan" class="new-complex-plan about-plane">

          <ul class="col-xs-12 zero-padding ap-complex-fix text-left">
            <li role="presentation" class="active bcm fix-padding-a" id="nav-complex-plan" data-complex_id="<?php print $complex_id; ?>";>
              <a>
                <label style="padding-top:15px;">
                  Дом
                </label>
                <?php print $img_hover; ?>
              </a>
            </li>
            <li role="presentation" class="bcm fix-padding-a" id="nav-home-plan" data-home_id="">
              <a class="not-allowed"  title="Выберите дом, чтобы узнать о количестве и планировках квартир в продаже">
                <label style="padding-top:15px;">
                  Секция
                </label>
                <?php print $img_hover; ?>
              </a>
            </li>
            <li role="presentation" class="bcm fix-padding-a" id="nav-floor-plan" data-section_id="">
              <a class="not-allowed"  title="Выберите дом, чтобы узнать о количестве и планировках квартир в продаже">
                <label id="current_floor" style="padding-top:15px;">
                  Этаж
                </label>
                <?php print $img_hover; ?>
              </a>
            </li>
            <li class="bcm legend-block-menu active border-none" id="svg-legend" style="display: none;">
              <?php print $img_legend; ?>
            </li>
          </ul>

          <div class="col-xs-12 area-list">
            <ul id="floors-link">
              <li style="padding-right: 30px">Выберите дом, чтобы узнать о количестве и планировках квартир в продаже</li>
            </ul>
          </div>

          <div class="floatingmes">
            <div class="floatingmes-left">
              <p id="home_number"></p>
              <h5 id="object_title">дом</h5>
            </div>
            <div class="floatingmes-right">
              <h5>квартир <br>в продаже</h5>
              <label id="apt_all_count"><span id="apt_active_count"></span> / <span style="font-size:15px; color:#939393;" id="apt_total_count"></span></label>
              <p>1к+1c<span id="apt_1_count"></span></p>
              <p>2к+2c<span id="apt_2_count"></span></p>
              <p>3к+3c<span id="apt_3_count"></span></p>
              <p>4+&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span id="apt_other_count"></span></p>
            </div>
            <div class="progress-bar">
              <div class="progress-inner" id="home_readiness" style="width:0%;">
                <p id="home_readiness_title"></p>
              </div>
            </div>
            <div class="float-bottom-left">
              <h5>очередь</h5>
              <label id="home_queue"></label>
            </div>
            <div class="float-bottom-center">
              <h5>этажей</h5>
              <label id="home_floors"></label>
            </div>
            <div class="float-bottom-right">
              <h5>срок сдачи</h5>
              <label id="home_deadline"></label>
            </div>
          </div>

          <div class="tooltip-area">
            <div class="floatingmes-left-new">
              <p id="queue_number"></p>
              <h5>очередь</h5>
            </div>
            <div class="floatingmes-right-new">
              <h5>срок сдачи</h5>
              <label id="deadline"></label>
            </div>
          </div>

          <div class="col-xs-12 right-part-complex zero-padding" id="svg-plan">
            <?php if($complex_plan):?>
              <?php print $complex_plan;?>
            <?php endif;?>
          </div>
        </div>

      </div>

      <!-- --- -->

    </div>

<!--    <div role="tabpanel" class="tab-pane fade" aria-labelledby="home-tab" id="text2">
      <div class="container fin" style="height:100%;">
        <div class="col-xs-12" style="height:500px;">
          <?php /*if(isset($infrastructure_description)):*/?>
            <?php /*print $infrastructure_description; */?>
          <?php /*endif*/?>
        </div>
      </div>
    </div>-->

    <div role="tabpanel" class="tab-pane fade" aria-labelledby="home-tab" id="text3">
      <div class="container fin zero-padding">
        <div class="col-xs-11 col-xs-offset-1 doc-block">

          <?php print $views_documents; ?>

        </div>
      </div>
    </div>

  </div>
</div>

<?php print $modal;?>