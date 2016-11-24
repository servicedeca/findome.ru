<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8" />
</head>
<body>
<tbody>
<center>
<table width="800" cellspacing="0" cellpadding="0" border="0">
<tbody>
<tr>
<td bgcolor="#ffffff" align="center">
<table width="100%" cellspacing="0" cellpadding="0" border="0" bgcolor="#ffffff">
<tbody>
<tr>
<td>
<table width="100%" cellspacing="0" cellpadding="0" border="0" bgcolor="#ffffff" style="padding-right: 15px;
    padding-left: 15px;">
<tbody>
<tr style="height:80px;">
  <td width="200" valign="bottom" align="left" style="vertical-align: middle;">
    <?php print $logo;?>
  </td>
  <td width="600" valign="bottom" bgcolor="#ffffff" align="right" style="padding-right:10px; vertical-align: middle;">
    <font face="Helvetica Neue,Helvetica,Lucida Grande,tahoma,verdana,arial,sans-serif" style="font-size:16px;color:#4c4c4c;">
      Поиск квартир в новостройках
    </font>
  </td>
</tr>
</tbody>
<tbody class="vertical-align:middle;">
<tr style="height:80px;">
  <td colspan="2" width="800" valign="top" align="left" style="vertical-align: middle;">
    <font face="Helvetica Neue,Helvetica,Lucida Grande,tahoma,verdana,arial,sans-serif" style="font-size:25px;color:#4c4c4c; font-weight:bold;">
      Заявка №<?php print $node->field_booking_numbers[LANGUAGE_NONE][0]['value'];?> на обратный звонок
    </font>
  </td>
</tr>
<tr style="height:30px;">
  <td width="400" colspan="2" valign="top" align="left">
    <font face="Helvetica Neue,Helvetica,Lucida Grande,tahoma,verdana,arial,sans-serif" style="font-size:18px;color:#4c4c4c; font-weight:bold;">
      Общая информация
    </font>
  </td>
</tr>

<?php if(isset($developer)): ?>
  <tr style="height:30px;">
    <td width="400" valign="top" align="left" style="padding-left:25px;">
      <font face="Helvetica Neue,Helvetica,Lucida Grande,tahoma,verdana,arial,sans-serif" style="font-size:18px;color:#939393;">
        Застройщик
      </font>
    </td>
    <td width="400" valign="top" align="right">
      <font face="Helvetica Neue,Helvetica,Lucida Grande,tahoma,verdana,arial,sans-serif" style="font-size:18px;color:#4c4c4c;">
        <?php print $developer->name; ?>
      </font>
    </td>
  </tr>

<?php endif; ?>

<?php if(isset($complex)): ?>
<tr style="height:30px;">
  <td width="400" valign="top" align="left" style="padding-left:25px;">
    <font face="Helvetica Neue,Helvetica,Lucida Grande,tahoma,verdana,arial,sans-serif" style="font-size:18px;color:#939393;">
      Жилой комплекс
    </font>
  </td>
  <td width="400" valign="top" align="right">
    <font face="Helvetica Neue,Helvetica,Lucida Grande,tahoma,verdana,arial,sans-serif" style="font-size:18px;color:#4c4c4c;">
      <?php print $complex; ?>
    </font>
  </td>
</tr>
<?php endif; ?>

<?php if($number_home):?>
  <tr style="height:30px;">
    <td width="400" valign="top" align="left" style="padding-left:25px;">
      <font face="Helvetica Neue,Helvetica,Lucida Grande,tahoma,verdana,arial,sans-serif" style="font-size:18px;color:#939393;">
        Дом
      </font>
    </td>
    <td width="400" valign="top" align="right">
      <font face="Helvetica Neue,Helvetica,Lucida Grande,tahoma,verdana,arial,sans-serif" style="font-size:18px;color:#4c4c4c;">
        <?php print $number_home; ?>
      </font>
    </td>
  </tr>
  <tr style="height:30px;">
    <td width="400" valign="top" align="left" style="padding-left:25px;">
      <font face="Helvetica Neue,Helvetica,Lucida Grande,tahoma,verdana,arial,sans-serif" style="font-size:18px;color:#939393;">
        Секция
      </font>
    </td>
    <td width="400" valign="top" align="right">
      <font face="Helvetica Neue,Helvetica,Lucida Grande,tahoma,verdana,arial,sans-serif" style="font-size:18px;color:#4c4c4c;">
        <?php print $section; ?>
      </font>
    </td>
  </tr>
  <tr style="height:30px;">
    <td width="400" valign="top" align="left" style="padding-left:25px;">
      <font face="Helvetica Neue,Helvetica,Lucida Grande,tahoma,verdana,arial,sans-serif" style="font-size:18px;color:#939393;">
        Квартира
      </font>
    </td>
    <td width="400" valign="top" align="right">
      <font face="Helvetica Neue,Helvetica,Lucida Grande,tahoma,verdana,arial,sans-serif" style="font-size:18px;color:#4c4c4c;">
        <?php print $apartment_number; ?>
      </font>
    </td>
  </tr>
  <tr style="height:30px;">
    <td width="800" colspan="2" valign="top" align="right">
      <a href="<?php print $link_apartment; ?>" style="font-size:18px;color:#3e90b2; font-family:Tahoma; text-decoration:none;" target="_blank">
        <?php print $link_apartment; ?>
      </a>
    </td>
  </tr>
<?php endif; ?>
<!--
<tr style="height:30px;">
  <td width="400" valign="top" align="left" style="padding-left:25px;">
    <font face="Helvetica Neue,Helvetica,Lucida Grande,tahoma,verdana,arial,sans-serif" style="font-size:18px;color:#939393;">
      Способ покупки
    </font>
  </td>
  <td width="400" valign="top" align="right">
    <font face="Helvetica Neue,Helvetica,Lucida Grande,tahoma,verdana,arial,sans-serif" style="font-size:18px;color:#4c4c4c;">
      <?php //print $method_pay?>
    </font>
  </td>
</tr>
-->
<tr style="height:5px;">
  <td width="400" valign="bottom" align="left" style="padding-left:25px;">
  </td>
  <td width="400" valign="bottom" align="right">
  </td>
</tr>
<tr style="height:2px; background-color:#00b7e4;">
  <td width="400" valign="bottom" align="right">
  </td>
  <td width="400" valign="bottom" align="right">
  </td>
</tr>
<tr style="height:10px;">
  <td width="400" valign="bottom" align="left" style="padding-left:25px;">
  </td>
  <td width="400" valign="bottom" align="right">
  </td>
</tr>
<tr style="height:30px;">
  <td width="400" colspan="2" valign="top" align="left">
    <font face="Helvetica Neue,Helvetica,Lucida Grande,tahoma,verdana,arial,sans-serif" style="font-size:18px;color:#4c4c4c; font-weight:bold;">
      Покупатель
    </font>
  </td>
</tr>
<tr style="height:30px;">
  <td width="400" valign="top" align="left" style="padding-left:25px;">
    <font face="Helvetica Neue,Helvetica,Lucida Grande,tahoma,verdana,arial,sans-serif" style="font-size:18px;color:#939393;">
      Ф.И.О.
    </font>
  </td>
  <td width="400" valign="top" align="right">
    <font face="Helvetica Neue,Helvetica,Lucida Grande,tahoma,verdana,arial,sans-serif" style="font-size:18px;color:#4c4c4c;">
      <?php print $node->field_booking_name['und'][0]['value']; ?>
    </font>
  </td>
</tr>
<tr style="height:30px;">
  <td width="400" valign="top" align="left" style="padding-left:25px;">
    <font face="Helvetica Neue,Helvetica,Lucida Grande,tahoma,verdana,arial,sans-serif" style="font-size:18px;color:#939393;">
      Электронная почта
    </font>
  </td>
  <td width="400" valign="top" align="right">
    <font face="Helvetica Neue,Helvetica,Lucida Grande,tahoma,verdana,arial,sans-serif" style="font-size:18px;color:#4c4c4c;">
      <?php print $node->field_booking_email[LANGUAGE_NONE][0]['value']; ?>
    </font>
  </td>
</tr>
<tr style="height:30px;">
  <td width="400" valign="top" align="left" style="padding-left:25px;">
    <font face="Helvetica Neue,Helvetica,Lucida Grande,tahoma,verdana,arial,sans-serif" style="font-size:18px;color:#939393;">
      Телефон
    </font>
  </td>
  <td width="400" valign="top" align="right">
    <font face="Helvetica Neue,Helvetica,Lucida Grande,tahoma,verdana,arial,sans-serif" style="font-size:18px;color:#4c4c4c;">
      <?php print $node->field_booking_number_phone[LANGUAGE_NONE][0]['value'];?>
    </font>
  </td>
</tr>
<?php if(!empty($node->field_passport_id[LANGUAGE_NONE][0]['value']) &&
  !empty($node->field_passport_series[LANGUAGE_NONE][0]['value'])): ?>
  <tr style="height:30px;">
    <td width="400" valign="top" align="left" style="padding-left:25px;">
      <font face="Helvetica Neue,Helvetica,Lucida Grande,tahoma,verdana,arial,sans-serif" style="font-size:18px;color:#939393;">
        Паспортные данные
      </font>
    </td>
    <td width="400" valign="top" align="right">
      <font face="Helvetica Neue,Helvetica,Lucida Grande,tahoma,verdana,arial,sans-serif" style="font-size:18px;color:#4c4c4c;">
        <span style="color:#939393">номер</span> <?php print $node->field_passport_id[LANGUAGE_NONE][0]['value']?> <span style="color:#939393">серия</span>
        <?php print $node->field_passport_series[LANGUAGE_NONE][0]['value']?>
      </font>
    </td>
  </tr>
  <tr style="height:30px;">
    <td width="800" colspan="2" valign="top" align="right">
      <font face="Helvetica Neue,Helvetica,Lucida Grande,tahoma,verdana,arial,sans-serif" style="font-size:18px;color:#4c4c4c;">
        <span style="color:#939393">выдан </span><?php print $node->field_issued_by[LANGUAGE_NONE][0]['value'] . ' ' . $node->field_date_issue[LANGUAGE_NONE][0]['value']?>
      </font>
    </td>
  </tr>
<?php endif;?>

</tbody>
</table>
</td>
</tr>
</tbody>
</table>
</td>
</tr>
</tbody>
</table>
</center>
</tbody>
</body>
</html>