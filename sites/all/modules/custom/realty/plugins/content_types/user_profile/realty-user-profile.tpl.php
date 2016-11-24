<div class="container-fluid container-fix about-header all-credit-block">
<div class="about-header-layer">
<div class="col-xs-12 zero-padding complex-line">
</div>
<div class="ap-header-layer-top">
</div>
<div class="container fin">

  <ul class="col-xs-12 zero-padding text-center ap-complex-fix" role="tablist">
<!--    <li role="presentation" class="br">
      <a href="#comp"  role="tab" data-toggle="tab" aria-controls="home" aria-expanded="true">
        <?php /*print t('Сравнения'); */?>
        <?php /*print $img_strel; */?>
      </a>
    </li>-->

    <li role="presentation" class="active br">
      <a href="#booking" role="tab" data-toggle="tab" aria-controls="profile" aria-expanded="false">
        <?php print t('Заявки на квартиру'); ?>
        <?php print $img_strel; ?>
      </a>
    </li>

    <li role="presentation" class="br border-none">
      <a href="#mortg" role="tab" data-toggle="tab" aria-controls="profile" aria-expanded="false">
        <?php print t('Заявки на ипотеку'); ?>
        <?php print $img_strel; ?>
      </a>
    </li>

  </ul>


  <div class="tab-content">
<!--    <div role="tabpanel" class="tab-pane fade div-apartment-comprassion" aria-labelledby="home-tab" id="comp">
      <div class="col-xs-12">
        <?php /*print $comparison; */?>
      </div>

    </div>-->

    <div class="tab-pane fade active in" id="booking" role="tabpanel" aria-labelledby="profile-tab">
      <div class="col-xs-12 book-block">
        <?php print $booking; ?>
      </div>
    </div>

    <div class="tab-pane fade" id="mortg" role="tabpanel" aria-labelledby="profile-tab">
      <div class="col-xs-12 book-block">
        <?php print $mortgage; ?>
      </div>
    </div>

  </div>
</div>
</div>
</div>
<?php print $modal; ?>
<div class="modal fade modal_ajax" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true" id="modal_notify">
  <div class="container container-modal-aplication zero-padding" id="modal_ajax">
    <div class="col-xs-12 header-container-modal-stock header-block">
      <div class="vertical">
        <h2><?php print $modal_title; ?></h2>
      </div>
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <?php print $img_close; ?>
      </button>
    </div>

    <div class="col-xs-12 list-modal-stock zero-padding">
      <p><?php print $modal_text; ?></p>
    </div>
  </div>
</div>
