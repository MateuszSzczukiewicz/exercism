use time::{PrimitiveDateTime as DateTime, Duration};

// Returns a DateTime one billion seconds after start.
pub fn after(start: DateTime) -> DateTime {
    const GIGASECOND: i64 = 1 * 1000 * 1000 * 1000;

    start + Duration::seconds(GIGASECOND)
}
