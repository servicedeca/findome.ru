<div class="container fin">
  <div class="col-xs-6 list-menu">
    <?php print $img_profile; ?>
    <div>
      <h1 id="div-user-profile-name">
        <?php print $name; ?>
      </h1>
      </div>
  </div>
  <div class="col-xs-4 left-list-menu">
    <div class="col-xs-12 top-list-menu">
      <?php print $img_mail; ?>
      <div>
        <h2 id="div-user-profile-mail">
          <?php print $mail; ?>
        </h2>
      </div>
    </div>
    <div class="col-xs-12 bottom-list-menu">
      <?php print $img_phone; ?>
      <div>
        <h3 id="div-user-profile-phone">
          <?php print $phone; ?>
        </h3>
      </div>
    </div>
  </div>
  <div class="col-xs-2 ap-button ap-button-fix" data-toggle="modal" data-target=".modal_option" id="edit-profile">
    <p class="s-label-small">
      <?php print t('Изменить данные') . '<br>' . t('профиля');?>
    </p>
    <?php print $img_edit_profile; ?>
  </div>
</div>

<div class="modal fade modal_option" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <div id="div-edit-user-profile-form">
  <?php// print render($form);?>
    </div>
</div>
<div class="div-modal-booking-form">
</div>