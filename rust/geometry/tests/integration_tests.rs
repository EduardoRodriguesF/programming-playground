#[cfg(test)]
mod tests {
    use geometry::Rectangle;

    #[test]
    fn rectangle_calculates_area() {
        let rect = Rectangle::new(10, 5);

        assert_eq!(rect.area(), 50);
    }

    #[test]
    fn rectangle_is_validated_correctly() {
        let rect = Rectangle::new(10, 5);
        let invalid_rect = Rectangle::new(0, 5);

        assert!(rect.is_valid());
        assert!(!invalid_rect.is_valid());
    }
}
