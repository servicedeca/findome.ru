<?php if ($plan == TRUE): ?>
<div class="container-fluid container-fix about-header about-header-bigger" id="parallax" data-speed="3" data-type="background" style="background-image: url(<?php print $background; ?>); margin-bottom: 350px;">
  <div class="about-header-layer">
    <div class="col-xs-12 zero-padding complex-line">
    </div>
    <div class="ap-header-layer-top">
    </div>
<?php endif; ?>

    <div class="container fin">

      <div id="complex-plan" <?php $plan == TRUE ? print '' : print 'class="new-complex-plan about-plane"'; ?>>

        <ul class="col-xs-12 zero-padding ap-complex-fix text-left">
          <li role="presentation" class="active <?php $plan == FALSE ? print 'bcm' : print 'br'; ?> fix-padding-a" id="nav-complex-plan" data-complex_id="<?php print $complex_id; ?>";>
            <a>
              <label style="padding-top:15px;">
                Дом
              </label>
              <?php print $img_hover; ?>
            </a>
          </li>
          <li role="presentation" class="<?php $plan == FALSE ? print 'bcm' : print 'br'; ?> fix-padding-a" id="nav-home-plan" data-home_id="">
            <a class="not-allowed"  title="Выберите дом, чтобы узнать о количестве и планировках квартир в продаже">
              <label style="padding-top:15px;">
                Секция
              </label>
              <?php print $img_hover; ?>
            </a>
          </li>
          <li role="presentation" class="<?php $plan == FALSE ? print 'bcm' : print 'br'; ?> fix-padding-a" id="nav-floor-plan" data-section_id="">
            <a class="not-allowed"  title="Выберите дом, чтобы узнать о количестве и планировках квартир в продаже">
              <label id="current_floor" style="padding-top:15px;">
                Этаж
              </label>
              <?php print $img_hover; ?>
            </a>
          </li>
          <li class="<?php $plan == FALSE ? print 'bcm' : print 'br'; ?> legend-block-menu active border-none" id="svg-legend" style="display: none;">
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

<?php if ($plan = TRUE): ?>
  </div>
  <div class="container-fluid complex-map mt0" style="margin-top: 800px;">
    <?php print $map; ?>
  </div>

</div>
<?php endif; ?>

<?php print $modal;?>

