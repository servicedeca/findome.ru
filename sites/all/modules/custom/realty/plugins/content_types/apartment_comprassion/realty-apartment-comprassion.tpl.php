<?php if($nodes): ?>
  <?php foreach($nodes as $node):?>
    <?php print $node['title']; ?>
  <?php endforeach; ?>
<?php endif;?>

<div class="container fin">
  <div class="col-xs-6 header-menu">
    <h1>Сравнение</h1>
  </div>
</div>
<div class="container-fluid container-fix all-complex-block">
  <div class="ap-header-layer-top h15">
  </div>
  <div class="container fin">
    <div class="col-xs-7 comprassion-first-part">
      <?php if ($comparison_empty == true):?>
        <div class="col-xs-12 empty-message">
          <h3>Пока ни одна квартира не добавлена</h3>
          <p>добавить квартиру можно на странице квартиры</p>
          <a href="/search/1">Перейти к подбору квартир</a>
        </div>
      <?php else:?>
        <div class="col-xs-6 comprassion-part" id="comparison_apt_0">
          <div class="comprassion-bg apt-change" data-apt-id="">
          </div>
          <div class="apt-apt"></div>
          <h4 class="apt-status"></h4>
          <div class="apt-plan"></div><br>
          <label>площадь, м<sup>2</sup></label>
          <h2 class="apt-sq"></h2>
          <label>стоимость, руб.</label>
          <h3 class="apt-coast"></h3>
          <label>тип</label>
          <p class="apt-rooms"></p>
          <label>Жилой комплекс</label>
          <p class="apt-complex"></p>
          <label>Этаж</label>
          <p class="apt-floor"></p>
          <label>Цена за м<sup>2</sup>, руб.</label>
          <p class="apt-price"></p>
          <label>Материал стен</label>
          <p class="apt-material"></p>
          <label>Срок сдачи</label>
          <p class="apt-deadline"></p>
          <label>Высота потолка</label>
          <p class="apt-ceiling"></p>
          <label>Подземная парковка</label>
          <p class="apt-parking"></p>
          <label>Балкон</label>
          <p class="apt-balkon"></p>
          <label>Застройщик</label>
          <p class="apt-developer"></p>
          <label>Секция</label>
          <p class="apt-section"></p>
          <label>Адрес</label>
          <p class="apt-address"></p>
        </div>
        <div class="col-xs-6 comprassion-part comprassion-part-right" id="comparison_apt_1">
          <div class="comprassion-bg-two apt-change" data-apt-id="">
          </div>
          <div class="apt-apt"></div>
          <h4 class="apt-status"></h4>
          <div class="apt-plan"></div><br>
          <label>площадь, м<sup>2</sup></label>
          <h2 class="apt-sq"></h2>
          <label>стоимость, руб.</label>
          <h3 class="apt-coast"></h3>
          <label>тип</label>
          <p class="apt-rooms"></p>
          <label>Жилой комплекс</label>
          <p class="apt-complex"></p>
          <label>Этаж</label>
          <p class="apt-floor"></p>
          <label>Цена за м<sup>2</sup>, руб.</label>
          <p class="apt-price"></p>
          <label>Материал стен</label>
          <p class="apt-material"></p>
          <label>Срок сдачи</label>
          <p class="apt-deadline"></p>
          <label>Высота потолка</label>
          <p class="apt-ceiling"></p>
          <label>Подземная парковка</label>
          <p class="apt-parking"></p>
          <label>Балкон</label>
          <p class="apt-balkon"></p>
          <label>Застройщик</label>
          <p class="apt-developer"></p>
          <label>Секция</label>
          <p class="apt-section"></p>
          <label>Адрес</label>
          <p class="apt-address"></p>
        </div>
      <?php endif;?>
    </div>

    <div class="col-xs-5 comprassion-second-part">
      <div class="comprassion-button-border">
      </div>
      <a href="/search/1">
        <svg version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" width="12px" height="12px" viewBox="0 0 9.987 9.998" enable-background="new 0 0 9.987 9.998" xml:space="preserve">
						<path fill="#F6F6F6" d="M9.987,6.051H6.04v3.947H3.968V6.051H0V3.969h3.968V0H6.04v3.969h3.948V6.051z"/>
					</svg>
        Добавить квартиру</a>

      <div class="col-xs-12 zero-padding slider-overflow" id="apt-other">

      </div>
    </div>
  </div>
</div>

<?php print $modal; ?>