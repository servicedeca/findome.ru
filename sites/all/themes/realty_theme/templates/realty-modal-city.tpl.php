<div class="modal fade modal_cities" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">

  <div class="container container-modal-city zero-padding">
    <div class="col-xs-12 header-container-modal header-block">
      <div class="modal-text">
        <p>Город</p>
      </div>
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <?php print $img_close; ?>
      </button>
    </div>

    <div class="col-xs-12 list-modal-city">

      <?php foreach ($city as $cid => $city_name): ?>
        <div class="col-xs-4 modal-list-item">
          <li>
            <a data-cid="<?php print $cid; ?>" class="modal_checkbox city-submit">
              <span>
              <label><?php print $city_name; ?></label>
              </span>
            </a>
          </li>
        </div>
      <?php endforeach; ?>

    </div>
  </div>
</div>