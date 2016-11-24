<div class="container-fluid container-fix">

  <div class="row">
    <div class="col-xs-6 fifty height logo-block">
      <a href="#page-top">
        <?php print $logo?>
      </a>
      <div class="head-line">
      </div>
      <div class="big-head-line">
      </div>
    </div>
    <div class="col-xs-6 fifty height zero-padding header-block">
      <div class="header-text">
        <h2>Cервис подбора и online бронирования квартиры в новостройках</h2>
        <p>прямая связь с отделами продаж застройщиков</p>
        <p>online заявка на ипотеку в новостройке в ведущие банки</p>
        <a class="nav_slide_button nav-toggle" href="http://novosibirsk.findome.ru/about" target="_blank">
          Подробнее о проекте
        </a>
      </div>
    </div>
  </div>

  <div class="row relative">
    <div class="col-xs-12 header-parent">
      <div class="col-xs-12" id="header">
          <ul>
            <div class="display-none-logo">
              <a href="#" class="scrollup">
                <?php print $logo2?>
              </a>
            </div>
            <?php foreach($menu as $item): ?>
              <li>
                <?php print $item; ?>
              </li>
            <?php endforeach; ?>
          </ul>
        </div>
    </div>
  </div>
</div>