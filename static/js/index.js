$(document).ready(function(){
    const clipboard = new ClipboardJS('#btn-copy');
    clipboard.on('success', function () {
        Swal.fire('Copied!', 'URL has copied.', 'success');
    });

    $("#year").html(new Date().getFullYear());

    $("#url").on('input', () => {
        $("#btn-generate").attr('disabled', !$("#url").val().match("http(s)?://(.+)\.(.{2,})"));
    });

    $("#btn-generate").on('click', () => {
        if (!$("#url").val().match("http(s)?://(.+)\.(.{2,})")) {
            Swal.fire(
                'Oops',
                'Invalid URL format',
                'error'
            );
            return;
        }

        let formData = new FormData();
        formData.append('longUrl', btoa($("#url").val()));
        $.ajax({
            url : "/short",
            type: "POST",
            data : formData,
            processData: false,
            contentType: false,
            success:function(data){
                if (data.Code == 1) {
                    $("#shorturl").val(data.ShortUrl);
                    $("#btn-copy").attr("disabled", false);
                }
                else {
                    Swal.fire(
                        'Oops',
                        data.Message,
                        'error'
                    );
                }
            }
        });
    });
})