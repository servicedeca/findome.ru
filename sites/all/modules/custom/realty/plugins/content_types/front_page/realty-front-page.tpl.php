<div class="container-fluid m_nav">
  <div class="navbar-header">
    <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar"
            aria-expanded="false" aria-controls="navbar">
      <span class="sr-only">Toggle navigation</span>
      <span class="icon-bar"></span>
      <span class="icon-bar"></span>
      <span class="icon-bar"></span>
    </button>
    <a class="navbar-brand" href="/"><?php print $img_mlogo; ?></a>
  </div>
  <div id="navbar" class="navbar-collapse collapse">
    <ul class="nav navbar-nav">
      <li><a data-context="searchCon" data-toggle="modal" data-target=".modal_cities" class="contextCtr">Подбор
          квартир</a></li>
      <li><a data-context="complexCon" data-toggle="modal" data-target=".modal_cities" class="contextCtr">Жилые
          комплексы</a></li>
      <li><a data-context="developerCon" data-toggle="modal" data-target=".modal_cities"
             class="contextCtr">Застройщики</a></li>
      <li><a data-context="mortageCon" data-toggle="modal" data-target=".modal_cities" class="contextCtr">Ипотека</a>
      </li>
      <!--      <li><a href="#">Личный кабинет</a></li>
            <li><a href="#">Выход</a></li>-->
      <li class="lc"><a href="/about">О проекте</a></li>

    </ul>
  </div><!--/.nav-collapse -->
</div>

<div class="container-fluid findomemain">
  <div class="container fin container-m main-top" style="position:relative;">
    <?php print $img_white_logo; ?>
    <?php print $img_houses; ?>
    <?php print $img_houses_mobile; ?>
    <?php print $img_flats_main; ?>
    <?php print $img_net_main; ?>
    <?php print $img_line1; ?>
    <?php print $img_line2; ?>
    <h1>ПОИСК И ONLINE-БРОНИРОВАНИЕ <br>
      КВАРТИР В НОВОСТРОЙКАХ</h1>
  </div>
</div>

<div class="container fin container-m main-second">
  <div class="col-xs-12 zero-padding">
    <div class="col-xs-6 col-xs-offset-6 smart_ml0">
      <h2 class="findome_main-h2">Ищем и сравниваем тысячи <br>вариантов квартир от застройщиков</h2>
      <div class="col-xs-11 fin-input-line">

        <form class="form-horizontal col-xs-4 findome_main-flats" role="form">
          <div class="form-group">
            <select id="basic" class="selectpicker show-tick form-control" title="Кол-во комнат">
              <?php foreach ($types as $tid => $type): ?>
                <option data-value="tid-<?php print $tid; ?>"><?php print $type; ?></option>
              <?php endforeach; ?>
            </select>
          </div>
        </form>

        <form class="form-horizontal col-xs-4 findome_main-flats" role="form">
          <div class="form-group">
            <select id="basic2" class="selectpicker show-tick form-control" title="Выберите город">
              <?php foreach ($cities as $cid => $city): ?>
                <option data-value="cid-<?php print $cid; ?>"><?php print $city; ?></option>
              <?php endforeach; ?>
            </select>
          </div>
        </form>

        <a data-context="mainSearchCon" data-toggle="modal" data-target=".modal_cities"
           class="search_submit contextCtr findome_main-link col-xs-4">Найти квартиру</a>

      </div>

    </div>
    <?php print $img_mtf; ?>
    <?php print $img_mtf2; ?>
    <div class="col-xs-4 fm-textblock fm-textblock-fix">
      <?php print $img_fmi_1; ?>
      <h3>Выдача результатов</h3>
      <p>В результатах выдачи отображаются все актуальные варианты квартир от застройщиков, соответствующие заданным
        параметрам поиска</p>
      <a data-toggle="modal" data-target=".modal_cities" data-context="developerCon" class="contextCtr">Перейти к выбору
        застройщика</a>
    </div>
  </div>
</div>

<div class="container fin container-m  main-third">
  <?php print $img_fm_flatmodal; ?>
  <?php print $img_fm_flatplane; ?>
  <?php print $img_fm_iconsnake; ?>
  <div class="col-xs-4 col-xs-offset-7 fm-textblock" style="margin-top:75px;">
    <?php print $img_fmi_2; ?>
    <h3>ПОДРОБНЫЕ ПЛАНИРОВКИ</h3>
    <p>Подробная планировка каждой квартиры, расположение на этаже, удобная форма сравнения квартир в разных жилых
      комплексов</p>
    <a data-toggle="modal" data-target=".modal_cities" data-context="complexCon" class="contextCtr">Перейти к выбору
      жилого комплекса</a>
  </div>
  <div class="col-xs-4 fm-textblock fm-textblock-fixfix">
    <?php print $img_fmi_3; ?>
    <h3>ОТПРАВКА ЗАЯВКИ<br>НАПРЯМУЮ ЗАСТРОЙЩИКУ</h3>
    <p>Функционалом сервиса предусмотрена подача заявки на бронирование квартиры и на запрос на обратный звонок напрямую
      в отдел продаж застройщика</p>
  </div>
  <div class="col-xs-6 col-xs-offset-6 fm-textblock fm-textblock-fixfixfix" style="margin-top:75px;">
    <?php print $img_fmi_4; ?>
    <h3>ОБРАТНАЯ СВЯЗЬ</h3>
    <p>Специалист отдела продаж застройщика перезвонит Вам и ответит на все интересующие вопросы</p>
    <!--    <a data-toggle="modal" data-target=".modal_cities" data-context="searchCon" class="contextCtr">Перейти к подбору
          квартиры</a>-->

  </div>

  <div class="col-xs-6 col-xs-offset-6 smart_ml0">
    <div class="col-xs-11 fin-input-line fin-input-line-fix">

      <form class="form-horizontal col-xs-4 findome_main-flats" role="form">
        <div class="form-group">
          <select id="basic" class="selectpicker show-tick form-control" title="Кол-во комнат">
            <?php foreach ($types as $tid => $type): ?>
              <option data-value="tid-<?php print $tid; ?>"><?php print $type; ?></option>
            <?php endforeach; ?>
          </select>
        </div>
      </form>

      <form class="form-horizontal col-xs-4 findome_main-flats" role="form">
        <div class="form-group">
          <select id="basic2" class="selectpicker show-tick form-control" title="Выберите город">
            <?php foreach ($cities as $cid => $city): ?>
              <option data-value="cid-<?php print $cid; ?>"><?php print $city; ?></option>
            <?php endforeach; ?>
          </select>
        </div>
      </form>

      <a data-context="mainSearchCon" data-toggle="modal" data-target=".modal_cities" class="search_submit contextCtr findome_main-link col-xs-4">
        Найти квартиру
      </a>
    </div>
  </div>

</div>

<div class="container container-m mobile-footer">
  <div class="col-xs-12 m_footer-socialline">
    <svg version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
         width="46.832px" height="46.837px" viewBox="0 0 46.832 46.837" enable-background="new 0 0 46.832 46.837"
         xml:space="preserve">

						<path fill="#EFEFEF" d="M40.792,22.411c0.632-0.817,1.134-1.473,1.505-1.968c2.67-3.55,3.827-5.817,3.472-6.806l-0.139-0.232
						c-0.092-0.139-0.332-0.267-0.718-0.382c-0.386-0.116-0.88-0.134-1.481-0.058l-6.667,0.047c-0.154-0.015-0.309-0.012-0.463,0.011
						c-0.154,0.023-0.255,0.047-0.301,0.069c-0.047,0.024-0.085,0.042-0.116,0.058l-0.092,0.069c-0.077,0.046-0.162,0.127-0.255,0.243
						c-0.093,0.116-0.17,0.25-0.232,0.405c-0.725,1.867-1.551,3.604-2.477,5.209c-0.571,0.957-1.096,1.787-1.574,2.488
						c-0.479,0.703-0.88,1.22-1.204,1.551c-0.324,0.332-0.618,0.599-0.88,0.799c-0.263,0.201-0.463,0.286-0.602,0.255
						c-0.139-0.031-0.27-0.061-0.394-0.093c-0.216-0.138-0.39-0.327-0.521-0.567c-0.131-0.239-0.22-0.54-0.266-0.903
						c-0.046-0.362-0.074-0.675-0.081-0.938c-0.008-0.262-0.004-0.632,0.012-1.111c0.015-0.479,0.023-0.802,0.023-0.972
						c0-0.586,0.012-1.223,0.035-1.91c0.023-0.686,0.042-1.231,0.058-1.632c0.015-0.401,0.023-0.826,0.023-1.273
						c0-0.447-0.027-0.799-0.081-1.054c-0.054-0.254-0.135-0.501-0.243-0.741c-0.108-0.239-0.266-0.424-0.475-0.555
						c-0.208-0.131-0.467-0.235-0.775-0.313c-0.818-0.186-1.86-0.285-3.125-0.301c-2.871-0.03-4.715,0.155-5.533,0.556
						c-0.324,0.17-0.618,0.401-0.88,0.695c-0.278,0.34-0.316,0.525-0.116,0.555c0.926,0.139,1.582,0.471,1.968,0.996l0.139,0.278
						c0.108,0.201,0.216,0.556,0.324,1.065c0.108,0.509,0.177,1.072,0.209,1.69c0.077,1.127,0.077,2.091,0,2.894
						c-0.077,0.803-0.15,1.428-0.22,1.874c-0.07,0.448-0.174,0.81-0.312,1.088c-0.139,0.279-0.232,0.448-0.278,0.51
						c-0.047,0.061-0.085,0.1-0.116,0.116c-0.201,0.077-0.409,0.116-0.625,0.116c-0.216,0-0.479-0.108-0.787-0.325
						c-0.309-0.215-0.629-0.513-0.961-0.891c-0.332-0.378-0.706-0.907-1.123-1.586c-0.417-0.678-0.849-1.481-1.296-2.407l-0.37-0.672
						c-0.232-0.431-0.548-1.061-0.949-1.886c-0.401-0.826-0.757-1.624-1.065-2.396c-0.124-0.324-0.309-0.57-0.556-0.741l-0.116-0.069
						c-0.077-0.061-0.201-0.127-0.371-0.196C9.555,13,9.379,12.95,9.193,12.919L2.85,12.965c-0.648,0-1.088,0.147-1.319,0.441
						l-0.093,0.139c-0.047,0.078-0.07,0.201-0.07,0.371c0,0.17,0.047,0.378,0.139,0.625c0.926,2.177,1.933,4.276,3.021,6.297
						c1.088,2.022,2.034,3.651,2.836,4.885c0.803,1.236,1.62,2.4,2.454,3.496c0.834,1.096,1.385,1.798,1.655,2.106
						c0.27,0.309,0.482,0.541,0.636,0.695l0.579,0.556c0.37,0.37,0.915,0.814,1.632,1.331c0.718,0.517,1.512,1.026,2.385,1.527
						c0.872,0.502,1.887,0.91,3.044,1.227c1.157,0.317,2.284,0.444,3.38,0.382h2.662c0.54-0.046,0.949-0.215,1.227-0.509l0.092-0.116
						c0.061-0.092,0.12-0.235,0.174-0.428c0.054-0.193,0.081-0.405,0.081-0.636c-0.016-0.663,0.035-1.263,0.15-1.794
						c0.116-0.533,0.247-0.933,0.394-1.204c0.147-0.269,0.312-0.497,0.498-0.683c0.185-0.186,0.316-0.297,0.394-0.335
						c0.077-0.038,0.139-0.065,0.185-0.081c0.37-0.123,0.806-0.004,1.308,0.359c0.501,0.364,0.972,0.81,1.412,1.343
						c0.44,0.533,0.968,1.13,1.586,1.794c0.617,0.663,1.157,1.157,1.62,1.481l0.463,0.279c0.309,0.185,0.709,0.354,1.204,0.509
						c0.494,0.154,0.926,0.193,1.296,0.116l5.927-0.093c0.586,0,1.042-0.096,1.366-0.289c0.324-0.192,0.517-0.405,0.579-0.636
						c0.061-0.232,0.065-0.493,0.012-0.787c-0.054-0.293-0.108-0.497-0.162-0.613c-0.054-0.116-0.104-0.213-0.151-0.289
						c-0.772-1.389-2.246-3.095-4.422-5.116l-0.047-0.046l-0.023-0.023l-0.023-0.023h-0.023c-0.988-0.942-1.613-1.574-1.875-1.899
						c-0.478-0.616-0.587-1.242-0.324-1.874C38.894,24.966,39.588,23.955,40.792,22.411z"/>
						</svg>
  </div>
  <div class="col-xs-12 m_footer-contactline">
    <p>
      <svg version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
           width="24.89px"
           height="22.625px" viewBox="0 0 24.89 22.625" enable-background="new 0 0 24.89 22.625" xml:space="preserve">
						<path fill="#FFFFFF" d="M21.416,3.336c0,0-2.408-3.867-5.909-1.682C12.006,3.84,9.312,6.437,8.276,8.653
						C7.239,10.869,4.49,16.61,7.001,19.724c0,0,1.369,1.454,2.953,2.224l0.745-6.05c0,0-1.502-0.751-0.938-2.129
						c0.564-1.378,3.886-6.635,3.886-6.635s1.138-1.587,2.691-0.52L21.416,3.336z"/>
        <path fill="#FFFFFF" d="M21.691,3.792c0,0,0.286,0.242,0.315,0.984c0.03,0.743-0.226,0.897-0.226,0.897l-3.501,2.186
						c0,0-0.297-0.028-0.623-0.107c-0.327-0.079-1.032-0.551-0.889-0.776C16.911,6.751,21.691,3.792,21.691,3.792z"/>
        <path fill="#FFFFFF" d="M11.283,16.011l1.277,0.768c0,0,0.204,0.222,0.193,0.782c-0.012,0.56-0.415,3.708-0.415,3.708
						s-0.093,0.54-0.512,0.655c-0.419,0.116-1.34,0.326-1.34,0.326L11.283,16.011z"/>
						</svg>

      +7 (383) 354-14-33
    </p>
    <p>
      <svg version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
           width="24.89px"
           height="22.625px" viewBox="0 0 24.89 22.625" enable-background="new 0 0 24.89 22.625" xml:space="preserve">
						<polygon fill="#FFFFFF" points="24.12,3.742 0.77,3.742 12.445,11.575 		"/>
        <polygon fill="#FFFFFF" points="12.445,13.867 0.662,5.963 0.662,19.551 24.228,19.551 24.228,5.963 		"/>
						</svg>
      findome@mail.ru
    </p>
  </div>
  <div class="col-xs-12 m_footer-bottomline">
    <p style="margin-bottom:0px;">© 2015 findome.ru При использовании материалов гиперссылка на <a
        href="/">findome.ru</a>
      обязательна.</p>
  </div>

</div>