#pragma once

namespace math {
class __EXPORT Butter2 {
 public:
  // constructor
  // Coefficients from http://www-users.cs.york.ac.uk/~fisher/mkfilter
  //

  // filtertype  = Butterworth
  // passtype  = Lowpass
  // ripple  =
  // order = 2
  // samplerate  = 280
  // corner1 = 5
  // corner2 =
  // adzero  =
  // logmin  = -20
  Butter2() {
    /*gain_ = 3.43259181e+02;
    a_[0] = -8.53274686e-01;
    a_[1] = 1.84162168e+00;*/
    /* gain_ = 4.143204922e+03;
    a_[0] = -0.9565436765;
    a_[1] = 1.9555782403; */
    // 10 Hz cutoff
    /*gain_ = 1.058546241e+03;
    a_[0] = -0.9149758348;
    a_[1] = 1.9111970674; */
    // 15 Hz cutoff
    gain_ = 4.806381793e+02;
    a_[0] = -0.8752145483;
    a_[1] = 1.8668922797;
  }
  /**
   * Add a new raw value to the filter
   *
   * @return retrieve the filtered result
   */
  float apply(float sample) {
    xs_[0] = xs_[1];
    xs_[1] = xs_[2];
    xs_[2] = sample / gain_;
    ys_[0] = ys_[1];
    ys_[1] = ys_[2];
    ys_[2] =
        (xs_[0] + xs_[2]) + 2 * xs_[1] + (a_[0] * ys_[0]) + (a_[1] * ys_[1]);
    return ys_[2];
  }

  /**
   * Reset the filter state to this value
   */
  float reset(float sample) {
    xs_[0] = sample;
    xs_[1] = sample;
    xs_[2] = sample;
    ys_[0] = sample;
    ys_[1] = sample;
    ys_[2] = sample;
    return sample;
  }

 private:
  float a_[2] = {0.0};

  float gain_ = 0.0;

  float xs_[3] = {0.0};
  float ys_[3] = {0.0};
};

}  // namespace math