#[derive(Clone, Debug, PartialEq, Eq)]
pub struct Clock {
    hours: i32,
    minutes: i32,
}

impl Clock {
    pub fn new(hours: i32, minutes: i32) -> Self {
        let total_minutes = hours * 60 + minutes;
        let normalized = total_minutes.rem_euclid(24 * 60);

        Self {
            hours: normalized / 60,
            minutes: normalized % 24,
        }
    }

    pub fn add_minutes(&self, minutes: i32) -> Self {
        Self::new(self.hours, self.minutes + minutes)
    }

    pub fn add_hours(&self, hours: i32) -> Self {
        Self::new(self.hours + hours, self.minutes)
    }

    pub fn to_string(&self) -> String {
        format!("{:02}:{:02}", self.hours, self.minutes)
    }
}
