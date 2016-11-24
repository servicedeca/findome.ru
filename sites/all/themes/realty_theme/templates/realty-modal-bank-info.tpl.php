
<div class="col-xs-12 header-container-modal-stock header-block">
  <div class="vertical">
    <h2><?php print $name; ?></h2>
  </div>
  <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
    <?php print $img_close; ?>
  </button>
</div>


<div class="col-xs-12 zero-padding bank-line">
  <div class="col-xs-3 bank-line-image" id="bank-id-need">
    <?php print $img_bank_logo; ?>
  </div>
</div>

<div class="col-xs-12 list-modal-stock zero-padding">
  <p><?php print $description; ?></p>
</div>
<div class="col-xs-12 modal-credit-list-body">
  <div class="modal-credit-separator">
  </div>
  <div class="col-xs-12 modal-credit-list">
    <div class="col-xs-4">
      <label>Номер лицензии:</label>
    </div>
    <div class="col-xs-6">
      <?php print $requisites['license']; ?>
    </div>
  </div>
  <div class="col-xs-12 modal-credit-list">
    <div class="col-xs-4">
      <label>ОГРН:</label>
    </div>
    <div class="col-xs-6">
      <p><?php print $requisites['ogrn']; ?></p>
    </div>
  </div>
  <div class="col-xs-12 modal-credit-list">
    <div class="col-xs-4">
      <label>БИК:</label>
    </div>
    <div class="col-xs-6">
      <p><?php print $requisites['bik']; ?></p>
    </div>
  </div>
  <div class="col-xs-12 modal-credit-list">
    <div class="col-xs-4">
      <label>Местонахождение:</label>
    </div>
    <div class="col-xs-6">
      <p><?php print $requisites['office']; ?></p>
    </div>
  </div>


  <div class="col-xs-12 modal-credit-list">
    <div class="col-xs-4">
      <label>Телефон:</label>
    </div>
    <div class="col-xs-6">
      <p><?php print $requisites['phone']; ?></p>
    </div>
  </div>

  <div class="col-xs-12 modal-credit-list">
    <div class="col-xs-4">
      <label>Официальный сайт:</label>
    </div>
    <div class="col-xs-6">
      <p><?php print $requisites['website']; ?></p>
    </div>
  </div>
</div>