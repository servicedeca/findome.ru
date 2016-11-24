<div class="container-fluid filter-line" data-speed="2" data-type="background">
  <div class="container fin">
    <div class="col-xs-12 zero-padding filter-container">
      <div class="col-xs-3 zero-padding">
        <h3>Квартир в<br>этом комплексе<span>0</span></h3>
      </div>
      <div class="col-xs-2 zero-padding filter-title-block">
        <p>Фильтры</p>
        <?php if($user->uid == 1): ?>
          <input type="textarea" id="find-number-apartment">
          <input type="button" id="find-number-apartment-button" value="ok">
        <?php endif;?>
      </div>
      <div class="col-xs-6 zero-padding filter-body">
        <a data-toggle="modal" data-target=".modal_address" class="col-xs-2 zero-padding filter-item">
          Адрес
          <?php print $img_flt_add; ?>
        </a>
        <a data-toggle="modal" data-target=".modal_type" class="col-xs-2 zero-padding filter-item">
          Комнаты
          <?php print $img_flt_add; ?>
        </a>
        <a data-toggle="modal" data-target=".modal_section" class="col-xs-2 zero-padding filter-item">
          Секция
          <?php print $img_flt_add; ?>
        </a>
        <a data-toggle="modal" data-target=".modal_floor" class="col-xs-2 zero-padding filter-item">
          Этаж
          <?php print $img_flt_add; ?>
        </a>
        <a data-toggle="modal" data-target=".modal_sq" class="col-xs-2 zero-padding filter-item">
          Площадь
          <?php print $img_flt_add; ?>
        </a>
        <div class="col-xs-2 zero-padding check-book" rel="tooltip" data-placement="bottom" title="Не отображать забронированные">
						<span>
						<input type="checkbox" />
							<label>
                <?php print $img_lock; ?>
              </label>
						</span>
        </div>
      </div>
      <button type="button" class="col-xs-1 zero-padding filter-item filter-button filter-clear" rel="tooltip" data-placement="bottom" title="Сбросить все фильтры">
        <?php print $img_cross; ?>
      </button>
    </div>
  </div>
</div>

<?php print render($view);?>

<?php print $modals; ?>
<?php print $modal_apartment; ?>