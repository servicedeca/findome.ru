<?php if ($wrapper == TRUE): ?>

  <div id="wrapper">
    <div class="container fin">
      <div class="col-xs-6 header-menu">
        <h1>ипотека<br><span>в новосибирске</span></h1>
      </div>
    </div>
  </div>

<?php endif; ?>

<div class="container-fluid container-fix about-header about-header-bigger" id="mortgage_block" <?php isset($apt_id) ? print 'data-apt-id="' . $apt_id . '"' : print 'data-city-id="' . $cityId .'"'; ?> data-type="background" style="background-image: url(<?php $background ? print $background : '';?>);"">
  <div class="about-header-layer">
    <div class="col-xs-12 zero-padding complex-line">
    </div>
    <div class="ap-header-layer-top">
    </div>
    <div class="container fin">

      <ul class="col-xs-12 zero-padding text-center ap-complex-fix" role="tablist">
        <li role="presentation" class="br <?php $bank_active == TRUE ? print 'active' : print ''; ?>">
          <a href="#banki"  role="tab" data-toggle="tab" aria-controls="profile" aria-expanded="false">
            Банки
            <?php print $img_hover; ?>
            </svg>
          </a>
        </li>

        <li role="presentation" class="br border-none <?php $bank_active == TRUE ? print '' : print 'active'; ?>">
          <a href="#iprog" role="tab" data-toggle="tab" aria-controls="home" aria-expanded="true">
            Ипотечные программы
            <?php print $img_hover; ?>
          </a>
        </li>
      </ul>

      <div id="accordion" class="accordion-block">

        <?php print $bank_list;?>

      </div>
    </div>
  </div>
</div>


<!-- Modal ajax -->
<div class="modal fade modal_ajax" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <div class="container container-modal-aplication zero-padding" id="modal_ajax">

  </div>
</div>