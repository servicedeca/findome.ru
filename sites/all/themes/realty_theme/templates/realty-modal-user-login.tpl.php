<div class="modal fade registration" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <div class="container container-modal-city zero-padding">
    <div class="col-xs-12 reg-tab-header zero-padding">
      <ul role="tablist" id="rtabh">
        <li class="active" role="presentation" >
          <a href="#entertab" role="tab" data-toggle="tab" aria-controls="profile" aria-expanded="false">
            <?php print t('Вход'); ?>
          </a>
        </li>
        <li class="separator-reg">|</li>
        <li role="presentation">
          <a href="#regtab" role="tab" data-toggle="tab" aria-controls="home" aria-expanded="true" class="reg-item">
            <?php print t('Регистрация'); ?>
          </a>
        </li>
      </ul>
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <?php print $image_close; ?>
      </button>
    </div>
    <div class="tab-content">

      <div role="tabpanel" class="tab-pane fade active in" id="entertab" aria-labelledby="home-tab">
        <?php print render($login_form);?>
      </div>

      <div role="tabpanel" class="tab-pane fade" id="regtab" aria-labelledby="profile-tab">
        <?php print render($register_form);?>
      </div>

    </div>
  </div>
</div>
