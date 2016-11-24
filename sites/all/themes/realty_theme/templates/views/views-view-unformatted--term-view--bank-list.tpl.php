<div class="tab-content">
  <div class="tab-pane fade in <?php $bank_active == TRUE ? print 'active' : print ''; ?>" aria-labelledby="profile-tab" id="banki">
    <div class="tab-pane">
      <?php foreach ($banks as $key => $bank): ?>
        <div class="col-xs-12 bank-line zero-padding">
          <div class="col-xs-3 zero-padding bank-line-image" id="bank-logo-<?php print $key; ?>">
            <?php print $bank['logo']; ?>
          </div>
          <div class="col-xs-1 bank-button"  data-toggle="modal" data-target=".modal_ajax" data-bank-id="<?php print $key; ?>" id="realty-bank-info">
            О банке
          </div>
          <div class="col-xs-2 col-xs-offset-2  bank-status-label">
            Рейтинг:
          </div>
          <div class="col-xs-1  bank-rating">
            <label>По активам</label>
          </div>
          <div class="col-xs-1  bank-rating">
            <label>По вкладам</label>
          </div>
          <div class="col-xs-1  bank-rating">
            <label>По кредитам</label>
          </div>
        </div>

        <div class="panel program_block">
          <a class="<?php isset($bank['class']) && $bank['class'] == "active" ? print 'm_programs': print 'm_programs collapsed'; ?>" data-toggle="collapse" data-parent=".tab-pane" href="#collapse<?php print $key; ?>">Ипотечные программы банка<?php print $img_bt; ?>
          </a>
          <div id="collapse<?php print $key; ?>" class="panel-collapse collapse <?php isset($bank['class']) && $bank['class'] == "active" ? print 'in': print ''; ?>" <?php isset($bank['class']) && $bank['class'] == "active" ? print '': print 'style="height: 0px;"'; ?>>
            <div class="panel-body bank-list-body">
              <table class="bank-table">

                <tr>
                  <th></th>
                  <th>ставка</th>
                  <th>сумма кредита</th>
                  <th>первоначальный взнос</th>
                  <th>срок кредита</th>
                  <th></th>
                </tr>

                <?php foreach ($bank['program'] as $mortgage): ?>
                  <!--<tr>
                  <td class="td-title">Заголовок</td>
                </tr>-->
                  <tr>
                    <td data-toggle="modal" data-target=".modal_ajax" class="td" id="realty-mortgage-info" data-bank-id="<?php print $key; ?>" data-mortgage-id="<?php print $mortgage['id']; ?>"><?php print $img_bankq; print $mortgage['name']; ?></td>
                    <td><?php print $mortgage['rate']; ?> %</td>
                    <td><?php is_numeric($mortgage['amount_max']) ? print 'до ' . number_format($mortgage['amount_max'], 0, '', ' ' ) . ' руб.' : print $mortgage['amount_max']; ?></td>
                    <td>от <?php print $mortgage['payment_min']; ?> %</td>
                    <td>до <?php print $mortgage['period_max']; ?> лет</td>
                    <td class="td-button modal_mortgage_request"  data-toggle="modal" data-target=".modal_ajax" id="realty-mortgage-apartment" data-bank-id="<?php print $key; ?>" data-mortgage-id="<?php print $mortgage['id']; ?>">отправить заявку</td>
                  </tr>

                <?php endforeach; ?>

              </table>
            </div>
          </div>
        </div>
      <?php endforeach; ?>

    </div>
  </div>

  <div class="tab-pane fade in <?php $bank_active == TRUE ? print '' : print 'active'; ?>" id="iprog" role="tabpanel" aria-labelledby="home-tab">
    <?php $i = 0;?>
    <?php foreach($categories as $category_name => $banks): ?>
      <div class="col-xs-12 bank-line zero-padding">
        <div class="col-xs-12 program-name"  data-toggle="modal" data-target=".modal_ajax" id="realty-mortgage-category-info" data-mortgage-category-id="<?php print current(current($banks))['category_id']; ?>">
          <?php print $category_name . $img_bankq; ?>
        </div>
      </div>

      <div class="panel program_block">
        <a class="m_programs collapsed" data-toggle="collapse" data-parent=".tab-pane" href="#collapseten-<?php print ++$i; ?>">Программы банков <?php print $img_bt; ?>
        </a>
        <div id="collapseten-<?php print $i; ?>" class="panel-collapse collapse <?php if($i == 1) print 'in'?>">
          <div class="panel-body bank-list-body">
            <table class="bank-table">
              <tr>
                <th style="padding-right: 10px;">Банк / название программы</th>
                <th>ставка</th>
                <th>сумма кредита</th>
                <th>первоначальный взнос</th>
                <th>срок кредита</th>
                <th></th>
              </tr>
            <?php foreach($banks as $bank_name => $mortgage): ?>

<!--                <tr>
                  <td class="td-title" data-toggle="modal" data-target=".modal_ajax" id="realty-bank-info" data-bank-id="<?php /*print current($mortgage)['bankId']; */?>"><?php /*print $bank_name; */?></td>
                </tr>-->

                <?php foreach($mortgage as $mortgage_name => $mortgage_info): ?>
                  <tr>
                    <td data-toggle="modal" data-target=".modal_ajax" class="td mort-prog" id="realty-mortgage-info" data-mortgage-id="<?php print $mortgage_info['id']; ?>" data-bank-id="<?php print $mortgage_info['bankId']; ?>"><?php print $img_bankq; ?><?php print $bank_name; ?><br><span><?php print $mortgage_name; ?></span></td>
                    <td><?php print $mortgage_info['rate'];?> %</td>
                    <td><?php is_numeric($mortgage_info['amount_max']) ? print 'до ' . number_format($mortgage_info['amount_max'], 0, '', ' ' ) . ' руб.' : print $mortgage_info['amount_max']; ?></td>
                    <td>от <?php print $mortgage_info['payment_min']; ?> %</td>
                    <td>до <?php print $mortgage_info['period_max']; ?> лет</td>
                    <td class="td-button modal_mortgage_request"  data-toggle="modal" data-target=".modal_ajax" id="realty-mortgage-apartment" data-mortgage-id="<?php print $mortgage_info['id']; ?>" data-bank-id="<?php print $mortgage_info['bankId']; ?>">отправить заявку</td>
                  </tr>

                <?php endforeach; ?>

            <?php endforeach; ?>
            </table>
          </div>
        </div>
      </div>
    <?php endforeach; ?>

  </div>
</div>