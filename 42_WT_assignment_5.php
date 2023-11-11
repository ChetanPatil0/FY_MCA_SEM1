<!DOCTYPE html>
<html lang="en">

<head>
   <meta charset="UTF-8">
   <meta name="viewport" content="width=device-width, initial-scale=1.0">
   <title>42_assignment_5</title>
   <?php
   function Bill_calc()
   {
      $unit = $_POST['unit'];
      $total_bill = 0.00;
      if ($_POST['unit'] <= 50) {
         $total_bill = 3.50 * $unit;
      } elseif ($unit > 50 && $unit <= 150) {
         $total_bill = 4.00 * $unit;
      } elseif ($unit > 150 && $unit <= 250) {
         $total_bill = 5.20 * $unit;
      } elseif ($unit > 250) {
         $total_bill = 6.50 * $unit;
      } else {
         echo "INVALID INPUT";
      }
      echo "YOUR UNIT IS : $unit<br> TOTAL ELECTRICITY BILL IS : Rs.$total_bill";
   }


   ?>
</head>

<body>
   <form action="" method="post"
      style="width:50vh; margin:auto; text-align:center;border:solid 3px red;padding:0px 15px 0px 15px; margin-top:100px;border-radius:10px;">
      <h1 style="color:crimson;">
         <center>Electricity Bill Calculater</center>
      </h1>
      <h3>ENTER UNITS :</h3>
      <input type="number" name="unit" placeholder="Enter the Units">
      <input type="submit" value="Submit" name="submit">
      <h3>
         <?php if (isset($_POST['submit'])) {
            Bill_calc();
         }
         ?>
      </h3>
   </form>
</body>

</html>