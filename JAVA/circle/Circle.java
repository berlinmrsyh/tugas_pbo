/**
 * The Circle class models a circle with a radius and color.
 */
public class Circle {    // Save as "Circle.java"
   // The public constants
   public static final double DEFAULT_RADIUS = 1.0;
   public static final String DEFAULT_COLOR  = "red";
   
   // The private instance variables
   private double radius;
   private String color;
   
   // The (overloaded) constructors
   /** Constructs a Circle with default radius and color */
   public Circle() {                   // 1st (default) Constructor
      this.radius = DEFAULT_RADIUS;
      this.color  = DEFAULT_COLOR;
   }
   /** Constructs a Circle with the given radius and default color */
   public Circle(double radius) {      // 2nd Constructor
      this.radius = radius;
      this.color = DEFAULT_COLOR;
   }
   /** Constructs a Circle with the given radius and color */
   public Circle(double radius, String color) { // 3rd Constructor
      this.radius = radius;
      this.color = color;
   }
   
   /** Returns the radius - the public getter for private variable radius. */
   public double getRadius() {
      return this.radius;
   }
   /** Sets the radius - the public setter for private variable radius */
   public void setRadius(double radius) {
      this.radius = radius;
   }
   /** Returns the color - the public getter for private variable color */
   public String getColor() {
      return this.color;
   }
   /** Sets the color - the public setter for private variable color */
   public void setColor(String color) {
      this.color = color;
   }
 
   /** Returns a self-descriptive string for this Circle instance */
   public String toString() {
      return "Circle[radius=" + radius + ", color=" + color + "]";
   }
 
   /** Returns the area of this Circle */
   public double getArea() {
      return radius * radius * Math.PI;
   }
 
   /** Returns the circumference of this Circle */
   public double getCircumference() {
      return 2.0 * radius * Math.PI;
   }
}