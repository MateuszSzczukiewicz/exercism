#[derive(Clone, Debug, PartialEq, Eq)]
pub struct Clock {
    hours: i32,
    minutes: i32,
}

impl Clock {
    pub fn new(hours: i32, minutes: i32) -> Self {
        Self { hours, minutes }
    }

    pub fn add_minutes(&self, minutes: i32) -> Self {
        let mut copy = self.clone();
        copy.minutes += minutes;

        copy
    }

    pub fn add_hours(&self, hours: i32) -> Self {
        let mut copy = self.clone();
        copy.hours += hours;

        copy
    }

    pub fn to_string(&self) -> String {
        format!("{:02}:{:02}", self.hours, self.minutes)
    }
}
