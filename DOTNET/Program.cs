using Microsoft.AspNetCore.Mvc;

var builder = WebApplication.CreateBuilder(args);
var app = builder.Build();

app.MapGet("/", () => "Hello World!");

app.MapPost("/saveproduct", (HttpContext context) =>
{
    // You need to bind the request body to the Product model
    var product = context.Request.ReadFromJsonAsync<Product>().Result;
    
    if (product == null) return "Product is null.";
    
    return $"{product.Name} - {product.Desc}";
});

app.MapGet("/getproduct", ([FromQuery] string dateStart, [FromQuery] string dateEnd) =>
{
    return $"{dateStart} - {dateEnd}";
});

app.MapGet("/getproduct/{code}", ([FromRoute] string code) => code);

app.Run();

public class Product
{
    public string Name { get; set; }
    public string Desc { get; set; } 
}