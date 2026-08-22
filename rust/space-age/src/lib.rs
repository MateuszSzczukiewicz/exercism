// The code below is a stub. Just enough to satisfy the compiler.
// In order to pass the tests you can add-to or change any of this code.

#[derive(Debug)]
pub struct Duration(u64);

impl From<u64> for Duration {
    fn from(s: u64) -> Self {
        Duration(s)
    }
}

fn calculate_years(d: &Duration, planet_year: f64) -> f64 {
    const SECONDS_PER_EARTH_YEAR: f64 = 31_557_600.0;

    let earth_years = d.0 as f64 / SECONDS_PER_EARTH_YEAR;

    earth_years / planet_year
}

pub trait Planet {
    const PLANET_YEAR: f64;

    fn years_during(d: &Duration) -> f64 {
        calculate_years(d, Self::PLANET_YEAR)
    }
}

pub struct Mercury;
pub struct Venus;
pub struct Earth;
pub struct Mars;
pub struct Jupiter;
pub struct Saturn;
pub struct Uranus;
pub struct Neptune;

impl Planet for Mercury {
    const PLANET_YEAR: f64 = 0.2408467;
}
impl Planet for Venus {
    const PLANET_YEAR: f64 = 0.61519726;
}
impl Planet for Earth {
    const PLANET_YEAR: f64 = 1.0;
}
impl Planet for Mars {
    const PLANET_YEAR: f64 = 1.8808158;
}
impl Planet for Jupiter {
    const PLANET_YEAR: f64 = 11.862615;
}
impl Planet for Saturn {
    const PLANET_YEAR: f64 = 29.447498;
}
impl Planet for Uranus {
    const PLANET_YEAR: f64 = 84.016846;
}
impl Planet for Neptune {
    const PLANET_YEAR: f64 = 164.79132;
}
