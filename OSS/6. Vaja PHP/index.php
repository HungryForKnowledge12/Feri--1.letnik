<?php
include('database.php');
session_start();
?>
<html>
<head>
    <title>Novice</title>
</head>
<body>
    <h1>Naslov strani</h1>
    <?php
    if(isset($_SESSION['username'])) {
        echo "Pozdravljeni, " . $_SESSION['username'] . "!";
        echo "<a href='logout.php'>Odjava</a>";
    } else {
        echo "<a href='login.php'>Prijava</a>";
    }

    foreach($articles as $article) {
        echo "<h2>" . $article['title'] . "</h2>";
        echo "<p>" . $article['summary'] . "</p>";
        echo "<a href='article.php?id=" . $article['id'] . "'>Preberi več</a>";
    }
    ?>
</body>
</html>