<?php if ($plan == FALSE): ?>
<div class="modal fade flat_modal" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <?php endif?>
  <?php if ($plan == TRUE): ?>
  <div style="display: none" id="plan-modal-trigger" data-toggle="modal" data-target=".plan_modal"></div>
  <div class="modal fade plan_modal" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
    <?php endif?>
    <div class="container container-modal-flat zero-padding">
      <div class="col-xs-12 header-container-flat header-block">
        <h2>Квартира<span id="apt-num"> </span></h2>
        <p id="apt-status"></p>
        <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
          <?php print $img_close; ?>
        </button>
      </div>
      <div class="col-xs-12 modal-flat-content zero-padding">
        <div class="col-xs-7 modal-flat-plane">

        </div>
        <div class="col-xs-3 zero-padding apartment-tab-header a-t-h-fix">
          <div class="col-xs-12 about-inner-item">
            <lebel>Общая площадь, м<sup>2</sup></lebel>
            <h1 id="sq"> </h1>
          </div>
          <div class="col-xs-12 about-inner-item">
            <lebel>Стоимость, руб.</lebel>
            <h3 id="cost"> </h3>
          </div>
          <div class="col-xs-12 about-inner-item">
            <lebel>Кол-во комнат</lebel>
            <h2 id="type"></h2>
          </div>
          <div class="col-xs-12 about-inner-item">
            <lebel>Жилой комплекс</lebel>
            <h2 id="complex"> </h2>
          </div>
          <div class="col-xs-12 about-inner-item">
            <lebel>Адрес</lebel>
            <h2 id="address"> </h2>
          </div>
          <div class="col-xs-12 about-inner-item">
            <lebel>Секция</lebel>
            <h2 id="section"> </h2>
          </div>
          <div class="col-xs-12 about-inner-item">
            <lebel>Этаж</lebel>
            <h2 id="floor"> </h2>
          </div>
          <div class="col-xs-12 about-inner-item">
            <lebel>Цена за м<sup>2</sup>, руб</lebel>
            <h2 id="price"></h2>
          </div>
          <div class="col-xs-12 about-inner-item">
            <lebel>Срок сдачи</lebel>
            <h2 id="deadline"> </h2>
          </div>
          <div class="col-xs-12 about-inner-item">
            <lebel>Жилая площадь, м<sup>2</sup></lebel>
            <h2 id="sq-live"> м<sup>2</sup></h2>
          </div>
          <div class="col-xs-12 about-inner-item">
            <lebel>застройщик</lebel>
            <h2 id="developer"> </h2>
          </div>
        </div>
        <div class="col-xs-2 zero-padding modal-button-block notification-open">
          <!--        <a href="apartment.html" class="col-xs-12 goto-flat" target="_blank">-->
          <!--          <p>подробная информация о квартире</p>-->
          <!--          --><?php //print $img_goto; ?>
          <!--        </a>-->
          <!---->
          <!--        <div id="id_comparison" class="col-xs-12 m_ap-button">-->
          <!---->
          <!--        </div>-->
          <!---->
          <!--        <div id="id_booking" class="col-xs-12 m_ap-button">-->
          <!---->
          <!--        </div>-->
          <!--        <div id="id_get_id" class="col-xs-12 m_ap-button">-->
          <!---->
          <!--        </div>-->

          <div class="col-xs-12 m_ap-button">
            <div class="vision">
              <div>
                <p>заявка отправляется напрямую застройщику, при этом за Вами фиксируется текущая стоимость квартиры</p>
              </div>
            </div>
            <div id="id_booking">
              <svg version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" width="19px"
                  height="19px" viewBox="0 0 19 19" style="enable-background:new 0 0 19 19;" xml:space="preserve">
										<polygon style="fill:#00B7E4;" points="9.5,11.2 0.6,4.9 0.6,15.1 18.4,15.1 18.4,4.9 		"/>
                <polygon style="fill:#00B7E4;" points="9.5,10.3 18.4,3.9 18.4,3.9 0.6,3.9 0.6,3.9 		"/>
              </svg>
              <p>
                Забронировать квартиру
              </p>
            </div>

          </div>
          <div class="col-xs-12 m_ap-button comparisonBlock">
            <div class="vision">
              <div>
                <p>сравнивайте квартиру по множеству параметров с предложениями от других застройщиков</p>
              </div>
            </div>
            <div id="id_comparison">
            <svg version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" width="19px"
                 height="19px" viewBox="0 0 17.7 18.9" style="enable-background:new 0 0 17.7 18.9;" xml:space="preserve">
										<polygon style="fill:#00B7E4;" points="2.2,13.3 2.2,2.5 12.9,2.5 12.9,8.6 14.8,8.6 14.8,0.7 0.4,0.7 0.4,15.1 7.9,15.1
											7.9,13.3 		"/>
              <path style="fill:#00B7E4;" d="M14.8,8.6h-1.8H7.9v4.7v1.8v3h9.5V8.6H14.8z M15.6,16.4H9.7v-1.2v-1.8v-2.9h3.3h1.8h0.8V16.4z"/>
								</svg>
            <p>
              Добавить в<br> сравнение
            </p>
            </div>
          </div>

          <div class="col-xs-12 m_ap-button">
            	<div class="vision">
              <div>
                <p>сохраните себе для печати подробную информацию о квартире с планировкой и параметрами.</p>
              </div>
            </div>
            <div id="id_get_id">
            <svg version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" width="19px"
              height="19px" viewBox="0 0 19 19" style="enable-background:new 0 0 19 19;" xml:space="preserve">
              <path style="fill:#00B7E4;" d="M14.5,9.9c-0.8,0-1.7,0.1-2.8,0.4c-1.1-0.9-2.2-1.9-3.2-2.9c0.3-3.2-0.2-4.5-0.7-5
                C7.4,1.9,6.9,1.7,6.3,1.9c-0.7,0.2-0.9,0.6-1,0.9C4.8,4.2,6.5,6.4,7.6,7.6c-0.2,1.5-0.5,3-0.9,4.4c-1,0.5-1.9,1-2.5,1.5
                c-0.8,0.6-1.3,1.3-1.4,1.8c-0.1,0.5,0.1,0.9,0.5,1.3c0.3,0.3,0.6,0.4,1,0.4h0c1.5,0,2.6-2.7,3.1-4.5c1.3-0.6,2.8-1.1,4.1-1.5
                c1.2,0.9,2.8,1.8,3.9,1.8c0.8,0,1.3-0.4,1.5-1.2c0.1-0.6-0.1-1-0.2-1.2C16.3,10.2,15.5,9.9,14.5,9.9z M4.2,16.3
                c-0.1,0-0.2-0.1-0.4-0.2c-0.2-0.2-0.2-0.4-0.2-0.6c0.1-0.6,1.1-1.5,2.7-2.4C5.5,15.4,4.7,16.3,4.2,16.3z M6,3.1
                c0-0.1,0.1-0.3,0.5-0.4c0.1,0,0.2,0,0.2,0c0.2,0,0.3,0.1,0.4,0.2c0.5,0.5,0.6,1.8,0.5,3.6C6.7,5.2,5.8,3.8,6,3.1z M10.6,10.6
                c-1,0.3-2,0.6-2.9,1l0,0l0,0c0.3-1,0.5-2.1,0.6-3.1l0,0l0,0C9.1,9.2,9.8,9.9,10.6,10.6L10.6,10.6L10.6,10.6z M16.1,11.7
                c-0.1,0.4-0.3,0.5-0.6,0.5c-0.6,0-1.6-0.4-2.8-1.2c0.7-0.1,1.3-0.2,1.9-0.2c1,0,1.4,0.2,1.5,0.4C16,11.2,16.1,11.4,16.1,11.7z"/>
            </svg>
            	<p>
              Версия для<br> печати
            </p>
            </div>
          </div>

          <div class="col-xs-12 m_ap-button goto-flat">
            <div class="vision">
              <div>
                <p>узнайте больше параметров, расположение на этаже, ипотечные условия</p>
              </div>
            </div>
            <svg version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" width="19px"
                 height="19px" viewBox="0 0 19 19" style="enable-background:new 0 0 19 19;" xml:space="preserve">
									<polygon style="fill:#00B7E4;" points="6.5,18.8 15.8,9.5 6.5,0.2 5.2,1.5 13.1,9.5 5.2,17.5 		"/>
							</svg>

            <p>
              Подробнее<br> о квартире
            </p>
          </div>

        </div>
      </div>
    </div>
  </div>
