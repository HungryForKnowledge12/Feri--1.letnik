$(document).ready(function() {
    var stevecOpravil = $('#seznamOpravil tr').length + 1;

    // Posodobi storage
    function updateLocalStorage() {
        var opravila = $('#seznamOpravil').html();
        var kategorije = $('#seznamKategorij').html();
        localStorage.setItem('opravila', opravila);
        localStorage.setItem('kategorije', kategorije);
    }

    // Nalaganje iz storage
    if (localStorage.getItem('opravila')) {
        $('#seznamOpravil').html(localStorage.getItem('opravila'));
        stevecOpravil = $('#seznamOpravil tr').length + 1;
    }
    if (localStorage.getItem('kategorije')) {
        $('#seznamKategorij').html(localStorage.getItem('kategorije'));
    }

    // Dodajanje nove kategorije
    $('#dodajKategorijo').click(function() {
        var kategorija = $('#novaKategorija').val();
        if (kategorija) {
            $('#seznamKategorij').append('<li class="list-group-item">' + kategorija + '</li>');
            $('#novaKategorija').val('');
            updateLocalStorage();
        }
    });

    // Brisanje izbrane kategorije
    $('#confirmDeleteCategory').click(function() {
        $('#seznamKategorij .list-group-item.active').remove();
        $('#deleteCategoryModal').modal('hide');
        updateLocalStorage();
    });

    // Izberi ali prekliči izbiro kategorije
    $('#seznamKategorij').on('click', '.list-group-item', function() {
        $('.list-group-item').removeClass('active');
        $(this).addClass('active');
    });

    // Dodajanje novega opravila
    $('#dodajOpravilo').click(function() {
        var opravilo = $('#novoOpravilo').val();
        var izbranaKategorija = $('#seznamKategorij .active').text();
        var datum = new Date().toISOString().slice(0, 10);

        if (opravilo && izbranaKategorija) {
            var vrstica = '<tr><td>' + stevecOpravil++ + '</td><td>' + opravilo + '</td><td>' + izbranaKategorija + '</td><td>' + datum + '</td></tr>';
            $('#seznamOpravil').append(vrstica);
            $('#novoOpravilo').val('');
            updateLocalStorage();
        } else {
            alert('Prosimo, izberite kategorijo in vnesite opravilo.');
        }
    });

    // Izberi ali prekliči izbiro opravila
    $('#seznamOpravil').on('click', 'tr', function() {
        $(this).toggleClass('table-danger');
    });

    // Brisanje izbranih opravil
    $('#izbrisiOpravila').click(function() {
        $('#seznamOpravil tr.table-danger').remove();
        updateLocalStorage();
    });
});
