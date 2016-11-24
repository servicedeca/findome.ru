<div class="container-fluid container-fix">

  <div class="row">
    <div class="col-xs-6 fifty height">
      <div class="map-title-block">
        <h1>
          <h3>Карта<span>Новостроек</span></h3>
        </h1>
      </div>
      <div class="head-line">
      </div>
      <div class="big-head-line">
      </div>
    </div>
    <div class="col-xs-6 fifty height zero-padding header-block">
      <div class="header-text">
        <h2>
          <?php print t('Квартиры от застройщиков на карте города')?>
        </h2>
        <p>
          <?php print t('Оцените местоположение новостроек в городе')?>
        </p>
      </div>
      <div id="card">
      </div>
    </div>
  </div>

  <div class="row relative margin-top-2">
    <div class="col-xs-9 fiftyplus big-height poster-photo parent" id="div-map-block" data-city-id="<?php print $city_tid?>">

      <div class="col-xs-12 mapfilter">
        <ul>
          <li class="pa_li">
            <span class="fspan">Фильтры</span>
          </li>
          <li>
            <a data-toggle="modal" data-target=".modal-map-area">Район</a>
          </li>
          <li>
            <a data-toggle="modal" data-target=".modal-map-developer" >Застройщик</a>
          </li>
          <li>
            <a data-toggle="modal" data-target=".modal-map-complex">ЖК</a>
          </li>
          <li>
            <a data-toggle="modal" data-target=".modal-map-category">Категории</a>
          </li>
          <li>
            <a class="mfilter_checkbox">
              <span>
                <input type="checkbox" id="mapcheck">
                <label class="map-hint"  for="mapcheck">
                  <?php print t('Stock');?>
                </label>
              </span>
            </a>
          </li>
        </ul>
      </div>
      <?php print render($map); ?>
    </div>

    <div class="big-height fiftyminus slider-info">
      <div class="col-xs-3 beige-block zero-padding">
        <div class="map-balun-image">
          <div class="shadow" id="ajax-map-balloon-image">
            <?php if(isset($image)):?>
              <?php print $image; ?>
            <?php endif;?>
          </div>
        </div>

        <div class="map-balun">
          <div id="ajax-map-balloon-logo">
            <?php if(isset($logo)):?>
              <?php print render($logo)?>
            <?php endif;?>
          </div>

          <div class="col-xs-12 third-quarter-item half-half-item  zero-padding display-table">
            <div class="vertical">
              <p id="ajax-map-balloon-description">
                <?php if(isset($description)):?>
                  <?php print $description;?>
                <?php endif?>
              </p>
            </div>
          </div>

          <div class="col-xs-12 link-item zero-padding half-half-item t80 display-table">
            <div id="ajax-map-balloon-details">
              <?php print $details?>
            </div>
          </div>
        </div>
        <div id="za">
        </div>

      </div>
    </div>
  </div>


</div>
<div id="za"></div>

<?php print $modal; ?>