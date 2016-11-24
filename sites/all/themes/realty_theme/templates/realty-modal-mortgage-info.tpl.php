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

  <?php if (isset($rates)): ?>
    <div class="col-xs-12 modal-credit-list">
      <div class="col-xs-5">
        <label>Ставки:</label>
      </div>
      <div class="col-xs-6">
        <?php foreach ($rates as $key => $rate) :?>

            <p><?php print $rate; ?></p>

        <?php endforeach; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (isset($rates)): ?>
    <div class="col-xs-12 modal-credit-list">
      <div class="col-xs-5">
        <label>Сумма кредита:</label>
      </div>
      <div class="col-xs-6">
        <?php foreach ($amounts as $key => $amount) :?>

            <p><?php print $amount; ?></p>

        <?php endforeach; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (isset($periods)): ?>
    <div class="col-xs-12 modal-credit-list">
      <div class="col-xs-5">
        <label>Срок кредита:</label>
      </div>
      <div class="col-xs-6">
        <?php foreach ($periods as $key => $period) :?>

            <p><?php print $period; ?></p>

        <?php endforeach; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (isset($payments)): ?>
    <div class="col-xs-12 modal-credit-list">
      <div class="col-xs-5">
        <label>Первоначальный взнос:</label>
      </div>
      <div class="col-xs-6">
        <?php foreach ($payments as $key => $payment) :?>

            <p><?php print $payment; ?></p>

        <?php endforeach; ?>
      </div>
    </div>
  <?php endif; ?>
</div>

<div class="col-xs-12 modal-credit-list-body">
  <div class="modal-credit-separator">
  </div>
  <div class="col-xs-12 modal-credit-list">
    <h3>Требования</h3>
  </div>

  <?php if (isset($requirement['age'])): ?>
    <div class="col-xs-12 modal-credit-list">
      <div class="col-xs-5">
        <label>Возраст заемщика:</label>
      </div>

      <div class="col-xs-6">
        <p><?php print $requirement['age']; ?></p>
      </div>

    </div>
  <?php endif; ?>

  <?php if (isset($requirement['age_men'])): ?>
    <div class="col-xs-12 modal-credit-list">
      <div class="col-xs-5">
        <label>Возраст в момент погашения кредита (для мужчин):</label>
      </div>

      <div class="col-xs-6">
        <p><?php print $requirement['age_men']; ?></p>
      </div>
    </div>
  <?php endif; ?>

  <?php if (isset($requirement['age_women'])): ?>
    <div class="col-xs-12 modal-credit-list">
      <div class="col-xs-5">
        <label>Возраст в момент погашения кредита (для женщин):</label>
      </div>

      <div class="col-xs-6">
        <p><?php print $requirement['age_women']; ?></p>
      </div>
    </div>
  <?php endif; ?>

  <?php if (isset($requirement['last_experience'])): ?>
    <div class="col-xs-12 modal-credit-list">
      <div class="col-xs-5">
        <label>Стаж на последнем месте работы:</label>
      </div>

      <div class="col-xs-6">
        <p><?php print $requirement['last_experience']; ?></p>
      </div>
    </div>
  <?php endif; ?>

  <?php if (isset($requirement['total_experience'])): ?>
    <div class="col-xs-12 modal-credit-list">
      <div class="col-xs-5">
        <label>Общий стаж работы:</label>
      </div>

      <div class="col-xs-6">
        <p><?php print $requirement['total_experience']; ?></p>
      </div>
    </div>
  <?php endif; ?>

  <?php if ($requirement['citizenship'] == 1): ?>
    <div class="col-xs-12 modal-credit-list">
      <div class="col-xs-5">
        <label>Наличие гражданства РФ:</label>
      </div>

      <div class="col-xs-6">
        <p>Обязательно</p>
      </div>
    </div>
  <?php endif; ?>

  <?php if ($requirement['living_place'] == 1): ?>
    <div class="col-xs-12 modal-credit-list">
      <div class="col-xs-5">
        <label>Наличие постоянной или временной регистрации в регионе обращения:</label>
      </div>

      <div class="col-xs-6">
        <p>Обязательно</p>
      </div>
    </div>
  <?php endif; ?>

  <?php if ($requirement['fixed_income'] == 1): ?>
    <div class="col-xs-12 modal-credit-list">
      <div class="col-xs-5">
        <label>Наличие постоянного дохода:</label>
      </div>

      <div class="col-xs-6">
        <p>Обязательно</p>
      </div>
    </div>
  <?php endif; ?>

  <?php if (isset($requirement['confirm'])): ?>
    <div class="col-xs-12 modal-credit-list">
      <div class="col-xs-5">
        <label>Форма подтверждения платёжеспособности:</label>
      </div>

      <div class="col-xs-6">
        <p><?php print $requirement['confirm']; ?></p>
      </div>
    </div>
  <?php endif; ?>

  <?php if (isset($requirement['documents'])): ?>
    <div class="col-xs-12 modal-credit-list">
      <div class="col-xs-5">
        <label>Необходимые документы:</label>
      </div>
      <div class="col-xs-6">

        <?php foreach ($requirement['documents'] as $key => $document) :?>

          <p><?php print $document; ?></p>

        <?php endforeach; ?>

      </div>
    </div>
  <?php endif; ?>

</div>

<div class="col-xs-12 modal-credit-list-body">
  <div class="modal-credit-separator">
  </div>
  <div class="col-xs-12 modal-credit-list">
    <h3>Условия</h3>
  </div>

  <?php if (isset($conditions['guarantees'])): ?>
    <div class="col-xs-12 modal-credit-list">
      <div class="col-xs-5">
        <label>Обеспечение кредита:</label>
      </div>
      <div class="col-xs-6">
        <?php foreach ($conditions['guarantees'] as $key => $guarante) :?>

            <p><?php print $guarante; ?></p>

        <?php endforeach; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (isset($conditions['early_rep'])): ?>
    <div class="col-xs-12 modal-credit-list">
      <div class="col-xs-5">
        <label>Досрочное погашение:</label>
      </div>

      <div class="col-xs-6">
        <p><?php print $conditions['early_rep']; ?></p>
      </div>
    </div>
  <?php endif; ?>

  <?php if (isset($conditions['insurance'])): ?>
    <div class="col-xs-12 modal-credit-list">
      <div class="col-xs-5">
        <label>Страхование:</label>
      </div>

      <div class="col-xs-6">
        <p><?php print $conditions['insurance']; ?></p>
      </div>
    </div>
  <?php endif; ?>
</div>

<div class="col-xs-12 modal-credit-list-body">
  <div class="modal-credit-separator">
  </div>
  <div class="col-xs-12 modal-credit-list">
    <h3>Дополнительно</h3>
  </div>

  <?php if (isset($additionally['fines'])): ?>
    <div class="col-xs-12 modal-credit-list">
      <div class="col-xs-5">
        <label>Штрафы:</label>
      </div>

      <div class="col-xs-6">
        <p><?php print $additionally['fines']; ?></p>
      </div>
    </div>
  <?php endif; ?>

  <?php if (isset($additionally['conditions'])): ?>
    <div class="col-xs-12 modal-credit-list">
      <div class="col-xs-5">
        <label>Дополнительные условия:</label>
      </div>

      <div class="col-xs-6">
        <p><?php print $additionally['conditions']; ?></p>
      </div>
    </div>
  <?php endif; ?>
</div>
